////////////////////////////////////////////////////////////////////////////////
// Copyright 2006 - 2008, Paul Beckingham.
// All rights reserved.
//
//
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>

#include "Config.h"
#include "Date.h"
#include "Table.h"
#include "stlmacros.h"
#include "TDB.h"
#include "T.h"
#include "task.h"

#ifdef HAVE_LIBNCURSES
#include <ncurses.h>
#endif

////////////////////////////////////////////////////////////////////////////////
void usage (Config& conf)
{
  Table table;
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  table.addColumn (" ");
  table.addColumn (" ");
  table.addColumn (" ");

  table.setColumnJustification (0, Table::left);
  table.setColumnJustification (1, Table::left);
  table.setColumnJustification (2, Table::left);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::flexible);
  table.setTableWidth (width);

  int row = table.addRow ();
  table.addCell (row, 0, "Usage:");
  table.addCell (row, 1, "task");

  row = table.addRow ();
  table.addCell (row, 1, "task add [tags] [attributes] description...");
  table.addCell (row, 2, "Adds a new task");

  row = table.addRow ();
  table.addCell (row, 1, "task list [tags] [attributes] description...");
  table.addCell (row, 2, "Lists all tasks matching the specified criteria");

  row = table.addRow ();
  table.addCell (row, 1, "task long [tags] [attributes] description...");
  table.addCell (row, 2, "Lists all task, all data, matching the specified criteria");

  row = table.addRow ();
  table.addCell (row, 1, "task ls [tags] [attributes] description...");
  table.addCell (row, 2, "Minimal listing of all tasks matching the specified criteria");

  row = table.addRow ();
  table.addCell (row, 1, "task completed [tags] [attributes] description...");
  table.addCell (row, 2, "Chronological listing of all completed tasks matching the specified criteria");

  row = table.addRow ();
  table.addCell (row, 1, "task ID [tags] [attributes] [description...]");
  table.addCell (row, 2, "Modifies the existing task with provided arguments");

  row = table.addRow ();
  table.addCell (row, 1, "task ID /from/to/");
  table.addCell (row, 2, "Perform the substitution on the description, for fixing mistakes");

  row = table.addRow ();
  table.addCell (row, 1, "task delete ID");
  table.addCell (row, 2, "Deletes the specified task");

  row = table.addRow ();
  table.addCell (row, 1, "task info ID");
  table.addCell (row, 2, "Shows all data, metadata for specified task");

  row = table.addRow ();
  table.addCell (row, 1, "task start ID");
  table.addCell (row, 2, "Marks specified task as started, starts the clock ticking");

  row = table.addRow ();
  table.addCell (row, 1, "task done ID");
  table.addCell (row, 2, "Marks the specified task as completed");

  row = table.addRow ();
  table.addCell (row, 1, "task projects");
  table.addCell (row, 2, "Shows a list of all project names used, and how many tasks are in each");

  row = table.addRow ();
  table.addCell (row, 1, "task tags");
  table.addCell (row, 2, "Shows a list of all tags used");

  row = table.addRow ();
  table.addCell (row, 1, "task summary");
  table.addCell (row, 2, "Shows a report of task status by project");

  row = table.addRow ();
  table.addCell (row, 1, "task history");
  table.addCell (row, 2, "Shows a report of task history, by month");

  row = table.addRow ();
  table.addCell (row, 1, "task next");
  table.addCell (row, 2, "Shows the most important tasks for each project");

  row = table.addRow ();
  table.addCell (row, 1, "task calendar");
  table.addCell (row, 2, "Shows a monthly calendar, with due tasks marked");

  row = table.addRow ();
  table.addCell (row, 1, "task active");
  table.addCell (row, 2, "Shows all task that are started, but not completed");

  row = table.addRow ();
  table.addCell (row, 1, "task overdue");
  table.addCell (row, 2, "Shows all incomplete tasks that are beyond their due date");

  row = table.addRow ();
  table.addCell (row, 1, "task stats");
  table.addCell (row, 2, "Shows task database statistics");

  row = table.addRow ();
  table.addCell (row, 1, "task usage");
  table.addCell (row, 2, "Shows task command usage frequency");

  row = table.addRow ();
  table.addCell (row, 1, "task export");
  table.addCell (row, 2, "Exports all tasks as a CSV file");

  row = table.addRow ();
  table.addCell (row, 1, "task version");
  table.addCell (row, 2, "Shows the task version number");

  std::cout << table.render ()
            << std::endl;

  std::cout
    << "ID is the numeric identifier displayed by the 'task list' command" << "\n"
    <<                                                                        "\n"
    << "Tags are arbitrary words, any quantity:"                           << "\n"
    << "  +tag               The + means add the tag"                      << "\n"
    << "  -tag               The - means remove the tag"                   << "\n"
    <<                                                                        "\n"
    << "Attributes are:"                                                   << "\n"
    << "  project:           Project name"                                 << "\n"
    << "  priority:          Priority"                                     << "\n"
    << "  due:               Due date"                                     << "\n"
    << "  fg:                Foreground color"                             << "\n"
    << "  bg:                Background color"                             << "\n"
    <<                                                                        "\n"
    << "Any command or attribute name may be abbreviated if still unique:" << "\n"
    << "  task list project:Home"                                          << "\n"
    << "  task li       pro:Home"                                          << "\n"
    <<                                                                        "\n"
    << "Some task descriptions need to be escaped because of the shell:"   << "\n"
    << "  task add \"quoted ' quote\""                                     << "\n"
    << "  task add escaped \\' quote"                                      << "\n"
    <<                                                                        "\n"
    << "Many characters have special meaning to the shell, including:"     << "\n"
    << "  $ ! ' \" ( ) ; \\ ` * ? { } [ ] < > | & % # ~"                   << "\n"
    << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
int main (int argc, char** argv)
{
// TODO Find out what this is, and either promote it to live code, or remove it.
//  std::set_terminate (__gnu_cxx::__verbose_terminate_handler);

  try
  {
    // Load the config file from the home directory.  If the file cannot be
    // found, offer to create a sample one.
    Config conf;
    struct passwd* pw = getpwuid (getuid ());
    if (!pw)
      throw std::string ("Could not read home directory from passwd file.");

    std::string home = pw->pw_dir;
    home += "/.taskrc";
    if (!conf.load (home))
      conf.createDefault (home);

    TDB tdb;
    tdb.dataDirectory (conf.get ("data.location"));

    // Log commands, if desired.
    if (conf.get ("command.logging") == "on")
      tdb.logCommand (argc, argv);

    // Parse the command line.
    std::vector <std::string> args;
    for (int i = 1; i < argc; ++i)
      args.push_back (argv[i]);

    std::string command;
    T task;
    parse (args, command, task);

         if (command == "add")                handleAdd            (tdb, task, conf);
    else if (command == "projects")           handleProjects       (tdb, task, conf);
    else if (command == "tags")               handleTags           (tdb, task, conf);
    else if (command == "list")               handleList           (tdb, task, conf);
    else if (command == "info")               handleInfo           (tdb, task, conf);
    else if (command == "long")               handleLongList       (tdb, task, conf);
    else if (command == "ls")                 handleSmallList      (tdb, task, conf);
    else if (command == "completed")          handleCompleted      (tdb, task, conf);
    else if (command == "delete")             handleDelete         (tdb, task, conf);
    else if (command == "start")              handleStart          (tdb, task, conf);
    else if (command == "done")               handleDone           (tdb, task, conf);
    else if (command == "export")             handleExport         (tdb, task, conf);
    else if (command == "version")            handleVersion        (           conf);
    else if (command == "summary")            handleReportSummary  (tdb, task, conf);
    else if (command == "next")               handleReportNext     (tdb, task, conf);
    else if (command == "history")            handleReportHistory  (tdb, task, conf);
    else if (command == "calendar")           handleReportCalendar (tdb, task, conf);
    else if (command == "active")             handleReportActive   (tdb, task, conf);
    else if (command == "overdue")            handleReportOverdue  (tdb, task, conf);
    else if (command == "stats")              handleReportStats    (tdb, task, conf);
    else if (command == "usage")              handleReportUsage    (tdb, task, conf);
    else if (command == "" && task.getId ())  handleModify         (tdb, task, conf);
    else                                      usage (conf);
  }

  catch (std::string& error)
  {
    std::cout << error << std::endl;
    return -1;
  }

  catch (...)
  {
    std::cout << "Unknown error." << std::endl;
    return -2;
  }

//  return 0;
  exit (0);
}

////////////////////////////////////////////////////////////////////////////////
std::string epochToString (const std::string& epoch)
{
  char formatted[12] = {0};

  if (epoch.length () && epoch.find ("/") == std::string::npos)
  {
    Date dt (::atoi (epoch.c_str ()));
    int m, d, y;
    dt.toMDY (m, d, y);
    sprintf (formatted, "%d/%d/%04d", m, d, y);
  }

  return formatted;
}

////////////////////////////////////////////////////////////////////////////////
void handleAdd (const TDB& tdb, T& task, Config& conf)
{
  char entryTime[16];
  sprintf (entryTime, "%u", (unsigned int) time (NULL));
  task.setAttribute ("entry", entryTime);

  if (task.getDescription () == "")
//    std::cout << "Cannot add a blank task" << std::endl;
    throw std::string ("Cannot add a blank task.");

  if (!tdb.addT (task))
    throw std::string ("Could not create new task.");
}

////////////////////////////////////////////////////////////////////////////////
void handleProjects (const TDB& tdb, T& task, Config& conf)
{
  // Get all the tasks, including deleted ones.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  // Scan all the tasks for their project name, building a map using project
  // names as keys.
  std::map <std::string, int> unique;
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T task (tasks[i]);
    unique[task.getAttribute ("project")] += 1;
  }

  // Render a list of project names from the map.
  Table table;
  table.addColumn ("Project");
  table.addColumn ("Tasks");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);

  table.setColumnJustification (1, Table::right);

  foreach (i, unique)
  {
    int row = table.addRow ();
    table.addCell (row, 0, i->first);
    table.addCell (row, 1, i->second);
  }

  std::cout << std::endl
            << table.render ()
            << std::endl
            << unique.size ()
            << (unique.size () == 1 ? " project" : " projects")
            << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void handleTags (const TDB& tdb, T& task, Config& conf)
{
  // Get all the tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  // Scan all the tasks for their project name, building a map using project
  // names as keys.
  std::map <std::string, std::string> unique;
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T task (tasks[i]);

    std::vector <std::string> tags;
    task.getTags (tags);

    for (unsigned int t = 0; t < tags.size (); ++t)
      unique[tags[t]] = "";
  }

  // Render a list of tag names from the map.
  foreach (i, unique)
    std::cout << i->first << std::endl;

  if (unique.size ())
    std::cout << std::endl
              << unique.size ()
              << (unique.size () == 1 ? " tag" : " tags")
              << std::endl;
  else
    std::cout << "No tags."
              << std::endl;

}

////////////////////////////////////////////////////////////////////////////////
// Successively apply filters based on the task object built from the command
// line.  Tasks that match all the specified criteria are listed.
void handleList (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  /* int count = */ tdb.gc ();

  // Get the pending tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("ID");
  table.addColumn ("Project");
  table.addColumn ("Pri");
  table.addColumn ("Due");
  table.addColumn ("Active");
  table.addColumn ("Age");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);
  table.setColumnUnderline (5);
  table.setColumnUnderline (6);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::minimum);
  table.setColumnWidth (3, Table::minimum);
  table.setColumnWidth (4, Table::minimum);
  table.setColumnWidth (5, Table::minimum);
  table.setColumnWidth (6, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (3, Table::right);
  table.setColumnJustification (5, Table::right);

  table.sortOn (3, Table::ascendingDate);
  table.sortOn (2, Table::descendingPriority);
  table.sortOn (1, Table::ascendingCharacter);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  // Iterate over each task, and apply selection criteria.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);

    // Apply description filter.
    unsigned int matches = 0;
    for (unsigned int w = 0; w < descWords.size (); ++w)
      if (refTask.getDescription ().find (descWords[w]) != std::string::npos)
        ++matches;

    if (matches == descWords.size ())
    {
      // Apply attribute filter.
      matches = 0;
      foreach (a, attrList)
        if (a->second == refTask.getAttribute (a->first))
          ++matches;

      if (matches == attrList.size ())
      {
        // Apply tag filter.
        matches = 0;
        for (unsigned int t = 0; t < tagList.size (); ++t)
          if (refTask.hasTag (tagList[t]))
            ++matches;

        if (matches == tagList.size ())
        {
          // Now format the matching task.
          bool imminent = false;
          bool overdue = false;
          Date now;
          std::string due = refTask.getAttribute ("due");
          if (due.length () && due.find ("/") == std::string::npos)
          {
            Date dt (::atoi (due.c_str ()));
            int m, d, y;
            dt.toMDY (m, d, y);
            char formatted[12];
            sprintf (formatted, "%d/%d/%04d", m, d, y);
            due = formatted;

            overdue = (dt < now) ? true : false;
            now += 7 * 86400;
            imminent = dt < now ? true : false;
          }

          std::string active;
          if (refTask.getAttribute ("start") != "")
            active = "*";

          std::string age;
          std::string created = refTask.getAttribute ("entry");
          if (created.length () && created.find ("/") == std::string::npos)
          {
            Date dt (::atoi (created.c_str ()));
            formatTimeDeltaDays (age, (time_t) (now - dt));
          }

          // All criteria match, so add refTask to the output table.
          int row = table.addRow ();
          table.addCell (row, 0, refTask.getId ());
          table.addCell (row, 1, refTask.getAttribute ("project"));
          table.addCell (row, 2, refTask.getAttribute ("priority"));
          table.addCell (row, 3, due);
          table.addCell (row, 4, active);
          table.addCell (row, 5, age);
          table.addCell (row, 6, refTask.getDescription ());

          if (conf.get ("color", true))
          {
            Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
            Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
            autoColorize (refTask, fg, bg);
            table.setRowFg (row, fg);
            table.setRowBg (row, bg);

            if (fg == Text::nocolor)
            {
              if (overdue)
                table.setCellFg (row, 3, Text::red);
              else if (imminent)
                table.setCellFg (row, 3, Text::yellow);
            }
          }
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No matches."
              << std::endl;

/*
  if (count)
    std::cout << std::endl
              << "[gc: "
              << count
              << " transferred]"
              << std::endl;
*/
}

////////////////////////////////////////////////////////////////////////////////
// Successively apply filters based on the task object built from the command
// line.  Tasks that match all the specified criteria are listed.  Show a narrow
// list that works better on mobile devices.
void handleSmallList (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  /* int count = */ tdb.gc ();

  // Get the pending tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("ID");
  table.addColumn ("Project");
  table.addColumn ("Pri");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::minimum);
  table.setColumnWidth (3, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (3, Table::left);

  table.sortOn (2, Table::descendingPriority);
  table.sortOn (1, Table::ascendingCharacter);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  // Iterate over each task, and apply selection criteria.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);

    // Apply description filter.
    unsigned int matches = 0;
    for (unsigned int w = 0; w < descWords.size (); ++w)
      if (refTask.getDescription ().find (descWords[w]) != std::string::npos)
        ++matches;

    if (matches == descWords.size ())
    {
      // Apply attribute filter.
      matches = 0;
      foreach (a, attrList)
        if (a->second == refTask.getAttribute (a->first))
          ++matches;

      if (matches == attrList.size ())
      {
        // Apply tag filter.
        matches = 0;
        for (unsigned int t = 0; t < tagList.size (); ++t)
          if (refTask.hasTag (tagList[t]))
            ++matches;

        if (matches == tagList.size ())
        {
          // Now format the matching task.
          bool imminent = false;
          bool overdue = false;
          Date now;
          std::string due = refTask.getAttribute ("due");
          if (due.length () && due.find ("/") == std::string::npos)
          {
            Date dt (::atoi (due.c_str ()));
            int m, d, y;
            dt.toMDY (m, d, y);
            char formatted[12];
            sprintf (formatted, "%d/%d/%04d", m, d, y);
            due = formatted;

            overdue = (dt < now) ? true : false;
            now += 7 * 86400;
            imminent = dt < now ? true : false;
          }

          std::string active;
          if (refTask.getAttribute ("start") != "")
            active = "*";

          std::string age;
          std::string created = refTask.getAttribute ("entry");
          if (created.length () && created.find ("/") == std::string::npos)
          {
            Date dt (::atoi (created.c_str ()));
            formatTimeDeltaDays (age, (time_t) (now - dt));
          }

          // All criteria match, so add refTask to the output table.
          int row = table.addRow ();
          table.addCell (row, 0, refTask.getId ());
          table.addCell (row, 1, refTask.getAttribute ("project"));
          table.addCell (row, 2, refTask.getAttribute ("priority"));
          table.addCell (row, 3, refTask.getDescription ());

          if (conf.get ("color", true))
          {
            Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
            Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
            autoColorize (refTask, fg, bg);
            table.setRowFg (row, fg);
            table.setRowBg (row, bg);

            if (fg == Text::nocolor)
            {
              if (overdue)
                table.setCellFg (row, 3, Text::red);
              else if (imminent)
                table.setCellFg (row, 3, Text::yellow);
            }
          }
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No matches."
              << std::endl;

/*
  if (count)
    std::cout << std::endl
              << "[gc: "
              << count
              << " transferred]"
              << std::endl;
*/
}

////////////////////////////////////////////////////////////////////////////////
// Successively apply filters based on the task object built from the command
// line.  Tasks that match all the specified criteria are listed.
void handleCompleted (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  /* int count = */ tdb.gc ();

  // Get the pending tasks.
  std::vector <T> tasks;
  tdb.completedT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("Done");
  table.addColumn ("Project");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (1, Table::left);
  table.setColumnJustification (2, Table::left);

  table.sortOn (0, Table::ascendingDate);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  // Iterate over each task, and apply selection criteria.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);

    // Apply description filter.
    unsigned int matches = 0;
    for (unsigned int w = 0; w < descWords.size (); ++w)
      if (refTask.getDescription ().find (descWords[w]) != std::string::npos)
        ++matches;

    if (matches == descWords.size ())
    {
      // Apply attribute filter.
      matches = 0;
      foreach (a, attrList)
        if (a->second == refTask.getAttribute (a->first))
          ++matches;

      if (matches == attrList.size ())
      {
        // Apply tag filter.
        matches = 0;
        for (unsigned int t = 0; t < tagList.size (); ++t)
          if (refTask.hasTag (tagList[t]))
            ++matches;

        if (matches == tagList.size ())
        {
          // Now format the matching task.
          Date end (::atoi (refTask.getAttribute ("end").c_str ()));

          // All criteria match, so add refTask to the output table.
          int row = table.addRow ();

          table.addCell (row, 0, end.toString ());
          table.addCell (row, 1, refTask.getAttribute ("project"));
          table.addCell (row, 2, refTask.getDescription ());

          if (conf.get ("color", true))
          {
            Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
            Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
            autoColorize (refTask, fg, bg);
            table.setRowFg (row, fg);
            table.setRowBg (row, bg);
          }
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No matches."
              << std::endl;

/*
  if (count)
    std::cout << std::endl
              << "[gc: "
              << count
              << " transferred]"
              << std::endl;
*/
}

////////////////////////////////////////////////////////////////////////////////
// Display all information for the given task.
void handleInfo (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  // Get all the tasks.
  std::vector <T> tasks;
  tdb.allPendingT (tasks);

  Table table;
  table.setTableWidth (width);

  table.addColumn ("Name");
  table.addColumn ("Value");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);

  table.setColumnJustification (0, Table::left);
  table.setColumnJustification (1, Table::left);

  // Find the task.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);

    if (refTask.getId () == task.getId ())
    {
      Date now;

      int row = table.addRow ();
      table.addCell (row, 0, "ID");
      table.addCell (row, 1, refTask.getId ());

      row = table.addRow ();
      table.addCell (row, 0, "Status");
      table.addCell (row, 1, (  refTask.getStatus () == T::pending   ? "Pending"
                              : refTask.getStatus () == T::completed ? "Completed"
                              : refTask.getStatus () == T::deleted   ? "Deleted"
                              : ""));

      row = table.addRow ();
      table.addCell (row, 0, "Description");
      table.addCell (row, 1, refTask.getDescription ());

      if (refTask.getAttribute ("project") != "")
      {
        row = table.addRow ();
        table.addCell (row, 0, "Project");
        table.addCell (row, 1, refTask.getAttribute ("project"));
      }

      if (refTask.getAttribute ("priority") != "")
      {
        row = table.addRow ();
        table.addCell (row, 0, "Priority");
        table.addCell (row, 1, refTask.getAttribute ("priority"));
      }

      // due (colored)
      bool imminent = false;
      bool overdue = false;
      std::string due = refTask.getAttribute ("due");
      if (due != "")
      {
        row = table.addRow ();
        table.addCell (row, 0, "Due");
        table.addCell (row, 1, epochToString (due));

        if (due.length () && due.find ("/") == std::string::npos)
        {
          Date dt (::atoi (due.c_str ()));

          overdue = (dt < now) ? true : false;
          now += 7 * 86400;
          imminent = dt < now ? true : false;

          if (conf.get ("color", true))
          {
            if (overdue)
              table.setCellFg (row, 1, Text::red);
            else if (imminent)
              table.setCellFg (row, 1, Text::yellow);
          }
        }
      }

      // start
      if (refTask.getAttribute ("start") != "")
      {
        row = table.addRow ();
        table.addCell (row, 0, "Start");
        table.addCell (row, 1, epochToString (refTask.getAttribute ("start")));
      }

      // end
      if (refTask.getAttribute ("end") != "")
      {
        row = table.addRow ();
        table.addCell (row, 0, "End");
        table.addCell (row, 1, epochToString (refTask.getAttribute ("end")));
      }

      // tags ...
      std::vector <std::string> tags;
      refTask.getTags (tags);
      if (tags.size ())
      {
        std::string allTags;
        join (allTags, " ", tags);

        row = table.addRow ();
        table.addCell (row, 0, "Tags");
        table.addCell (row, 1, allTags);
      }

      row = table.addRow ();
      table.addCell (row, 0, "UUID");
      table.addCell (row, 1, refTask.getUUID ());

      row = table.addRow ();
      table.addCell (row, 0, "Entered");
      std::string entry = epochToString (refTask.getAttribute ("entry"));

      std::string age;
      std::string created = refTask.getAttribute ("entry");
      if (created.length () && created.find ("/") == std::string::npos)
      {
        Date dt (::atoi (created.c_str ()));
        formatTimeDeltaDays (age, (time_t) (now - dt));
      }

      table.addCell (row, 1, entry + " (" + age + ")");
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No matches." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Successively apply filters based on the task object built from the command
// line.  Tasks that match all the specified criteria are listed.
void handleLongList (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  /* int count = */ tdb.gc ();

  // Get all the tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("ID");
  table.addColumn ("Project");
  table.addColumn ("Pri");
  table.addColumn ("Entry");
  table.addColumn ("Start");
  table.addColumn ("Due");
  table.addColumn ("Age");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);
  table.setColumnUnderline (5);
  table.setColumnUnderline (6);
  table.setColumnUnderline (7);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::minimum);
  table.setColumnWidth (3, Table::minimum);
  table.setColumnWidth (4, Table::minimum);
  table.setColumnWidth (5, Table::minimum);
  table.setColumnWidth (6, Table::minimum);
  table.setColumnWidth (7, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (3, Table::right);
  table.setColumnJustification (4, Table::right);
  table.setColumnJustification (5, Table::right);
  table.setColumnJustification (6, Table::right);

  table.sortOn (5, Table::ascendingDate);
  table.sortOn (2, Table::descendingPriority);
  table.sortOn (1, Table::ascendingCharacter);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  // Iterate over each task, and apply selection criteria.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);

    // Apply description filter.
    unsigned int matches = 0;
    for (unsigned int w = 0; w < descWords.size (); ++w)
      if (refTask.getDescription ().find (descWords[w]) != std::string::npos)
        ++matches;

    if (matches == descWords.size ())
    {
      // Apply attribute filter.
      matches = 0;
      foreach (a, attrList)
        if (a->second == refTask.getAttribute (a->first))
          ++matches;

      if (matches == attrList.size ())
      {
        // Apply tag filter.
        matches = 0;
        for (unsigned int t = 0; t < tagList.size (); ++t)
          if (refTask.hasTag (tagList[t]))
            ++matches;

        if (matches == tagList.size ())
        {
          Date now;

          std::string started = refTask.getAttribute ("start");
          if (started.length () && started.find ("/") == std::string::npos)
          {
            Date dt (::atoi (started.c_str ()));
            int m, d, y;
            dt.toMDY (m, d, y);
            char formatted[12];
            sprintf (formatted, "%d/%d/%04d", m, d, y);
            started = formatted;
          }

          std::string entered = refTask.getAttribute ("entry");
          if (entered.length () && entered.find ("/") == std::string::npos)
          {
            Date dt (::atoi (entered.c_str ()));
            int m, d, y;
            dt.toMDY (m, d, y);
            char formatted[12];
            sprintf (formatted, "%d/%d/%04d", m, d, y);
            entered = formatted;
          }

          // Now format the matching task.
          bool imminent = false;
          bool overdue = false;
          std::string due = refTask.getAttribute ("due");
          if (due.length () && due.find ("/") == std::string::npos)
          {
            Date dt (::atoi (due.c_str ()));
            int m, d, y;
            dt.toMDY (m, d, y);
            char formatted[12];
            sprintf (formatted, "%d/%d/%04d", m, d, y);
            due = formatted;

            overdue = (dt < now) ? true : false;
            now += 7 * 86400;
            imminent = dt < now ? true : false;
          }

          std::string age;
          std::string created = refTask.getAttribute ("entry");
          if (created.length () && created.find ("/") == std::string::npos)
          {
            Date dt (::atoi (created.c_str ()));
            formatTimeDeltaDays (age, (time_t) (now - dt));
          }

          // All criteria match, so add refTask to the output table.
          int row = table.addRow ();
          table.addCell (row, 0, refTask.getId ());
          table.addCell (row, 1, refTask.getAttribute ("project"));
          table.addCell (row, 2, refTask.getAttribute ("priority"));
          table.addCell (row, 3, entered);
          table.addCell (row, 4, started);
          table.addCell (row, 5, due);
          table.addCell (row, 6, age);
          table.addCell (row, 7, refTask.getDescription ());

          if (conf.get ("color", true))
          {
            Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
            Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
            autoColorize (refTask, fg, bg);
            table.setRowFg (row, fg);
            table.setRowBg (row, bg);

            if (fg == Text::nocolor)
            {
              if (overdue)
                table.setCellFg (row, 3, Text::red);
              else if (imminent)
                table.setCellFg (row, 3, Text::yellow);
            }
          }
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No matches." << std::endl;

/*
  if (count)
    std::cout << std::endl
              << "[gc: "
              << count
              << " transferred]"
              << std::endl;
*/
}

////////////////////////////////////////////////////////////////////////////////
// Project  Tasks  Avg Age  Status
// A           12      13d  XXXXXXXX------
// B          109   3d 12h  XX------------
void handleReportSummary (const TDB& tdb, T& task, Config& conf)
{
  // Generate unique list of project names.
  std::map <std::string, bool> allProjects;
  std::vector <T> pending;
  tdb.pendingT (pending);
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    T task (pending[i]);
    allProjects[task.getAttribute ("project")] = false;
  }

  std::vector <T> completed;
  tdb.completedT (completed);
  for (unsigned int i = 0; i < completed.size (); ++i)
  {
    T task (completed[i]);
    allProjects[task.getAttribute ("project")] = false;
  }

  // Initialize counts, sum.
  std::map <std::string, int> countPending;
  std::map <std::string, int> countCompleted;
  std::map <std::string, double> sumEntry;
  std::map <std::string, int> counter;
  time_t now = time (NULL);

  foreach (i, allProjects)
  {
    countPending   [i->first] = 0;
    countCompleted [i->first] = 0;
    sumEntry       [i->first] = 0.0;
    counter        [i->first] = 0;
  }

  // Count the pending tasks.
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    T task (pending[i]);
    std::string project = task.getAttribute ("project");
    ++countPending[project];

    time_t entry = ::atoi (task.getAttribute ("entry").c_str ());
    if (entry)
    {
      sumEntry[project] = sumEntry[project] + (double) (now - entry);
      ++counter[project];
    }
  }

  // Count the completed tasks.
  for (unsigned int i = 0; i < completed.size (); ++i)
  {
    T task (completed[i]);
    std::string project = task.getAttribute ("project");
    countCompleted[project] = countCompleted[project] + 1;
    ++counter[project];

    time_t entry = ::atoi (task.getAttribute ("entry").c_str ());
    time_t end   = ::atoi (task.getAttribute ("end").c_str ());
    if (entry && end)
      sumEntry[project] = sumEntry[project] + (double) (end - entry);
  }

  // Create a table for output.
  Table table;
  table.addColumn ("Project");
  table.addColumn ("Remaining");
  table.addColumn ("Avg age");
  table.addColumn ("Complete");
  table.addColumn ("0%                        100%");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);

  table.setColumnJustification (1, Table::right);
  table.setColumnJustification (2, Table::right);
  table.setColumnJustification (3, Table::right);

  table.sortOn (0, Table::ascendingCharacter);

  int barWidth = 30;
  foreach (i, allProjects)
  {
    if (countPending[i->first] > 0)
    {
      int row = table.addRow ();
      table.addCell (row, 0, (i->first == "" ? "(none)" : i->first));
      table.addCell (row, 1, countPending[i->first]);
      if (counter[i->first])
      {
        std::string age;
        formatTimeDeltaDays (age, (time_t) (sumEntry[i->first] / counter[i->first]));
        table.addCell (row, 2, age);
      }

      int c = countCompleted[i->first];
      int p = countPending[i->first];
      int completedBar = (c * barWidth) / (c + p);

      std::string bar;
      if (conf.get ("color", true))
      {
        bar = "\033[42m";
        for (int b = 0; b < completedBar; ++b)
          bar += " ";

        bar += "\033[40m";
        for (int b = 0; b < barWidth - completedBar; ++b)
          bar += " ";

        bar += "\033[0m";
      }
      else
      {
        for (int b = 0; b < completedBar; ++b)
          bar += "=";

        for (int b = 0; b < barWidth - completedBar; ++b)
          bar += " ";
      }
      table.addCell (row, 4, bar);

      char percent[12];
      sprintf (percent, "%d%%", 100 * c / (c + p));
      table.addCell (row, 3, percent);
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " project" : " projects")
              << std::endl;
  else
    std::cout << "No projects." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// A summary of the most important pending tasks.
//
// For every project, pull important tasks to present as an 'immediate' task 
// list.  This hides the overwhelming quantity of other tasks.
//
// Present at most three tasks for every project.  Select the tasks using
// these criteria:
//   - due:< 1wk, pri:*
//   - due:*, pri:H
//   - pri:H
//   - due:*, pri:M
//   - pri:M
//   - due:*, pri:L
//   - pri:L
//   - due:*, pri:*        <-- everything else
//
// Make the "three" tasks a configurable number
//
void handleReportNext (const TDB& tdb, T& task, Config& conf)
{
  // Load all pending.
  std::vector <T> pending;
  tdb.allPendingT (pending);

  // Restrict to matching subset.
  std::vector <int> matching;
  gatherNextTasks (tdb, task, conf, pending, matching);

  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  /* int gcCount = */ tdb.gc ();

  // Get the pending tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("ID");
  table.addColumn ("Project");
  table.addColumn ("Pri");
  table.addColumn ("Due");
  table.addColumn ("Active");
  table.addColumn ("Age");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);
  table.setColumnUnderline (5);
  table.setColumnUnderline (6);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::minimum);
  table.setColumnWidth (3, Table::minimum);
  table.setColumnWidth (4, Table::minimum);
  table.setColumnWidth (5, Table::minimum);
  table.setColumnWidth (6, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (3, Table::right);
  table.setColumnJustification (5, Table::right);

  table.sortOn (3, Table::ascendingDate);
  table.sortOn (2, Table::descendingPriority);
  table.sortOn (1, Table::ascendingCharacter);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  // Iterate over each task, and apply selection criteria.
  foreach (i, matching)
  {
    T refTask (pending[*i]);

    // Apply description filter.
    unsigned int matches = 0;
    for (unsigned int w = 0; w < descWords.size (); ++w)
      if (refTask.getDescription ().find (descWords[w]) != std::string::npos)
        ++matches;

    if (matches == descWords.size ())
    {
      // Apply attribute filter.
      matches = 0;
      foreach (a, attrList)
        if (a->second == refTask.getAttribute (a->first))
          ++matches;

      if (matches == attrList.size ())
      {
        // Apply tag filter.
        matches = 0;
        for (unsigned int t = 0; t < tagList.size (); ++t)
          if (refTask.hasTag (tagList[t]))
            ++matches;

        if (matches == tagList.size ())
        {
          // Now format the matching task.
          bool imminent = false;
          bool overdue = false;
          Date now;
          std::string due = refTask.getAttribute ("due");
          if (due.length () && due.find ("/") == std::string::npos)
          {
            Date dt (::atoi (due.c_str ()));
            int m, d, y;
            dt.toMDY (m, d, y);
            char formatted[12];
            sprintf (formatted, "%d/%d/%04d", m, d, y);
            due = formatted;

            overdue = (dt < now) ? true : false;
            now += 7 * 86400;
            imminent = dt < now ? true : false;
          }

          std::string active;
          if (refTask.getAttribute ("start") != "")
            active = "*";

          std::string age;
          std::string created = refTask.getAttribute ("entry");
          if (created.length () && created.find ("/") == std::string::npos)
          {
            Date dt (::atoi (created.c_str ()));
            formatTimeDeltaDays (age, (time_t) (now - dt));
          }

          // All criteria match, so add refTask to the output table.
          int row = table.addRow ();
          table.addCell (row, 0, refTask.getId ());
          table.addCell (row, 1, refTask.getAttribute ("project"));
          table.addCell (row, 2, refTask.getAttribute ("priority"));
          table.addCell (row, 3, due);
          table.addCell (row, 4, active);
          table.addCell (row, 5, age);
          table.addCell (row, 6, refTask.getDescription ());

          if (conf.get ("color", true))
          {
            Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
            Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
            autoColorize (refTask, fg, bg);
            table.setRowFg (row, fg);
            table.setRowBg (row, bg);

            if (fg == Text::nocolor)
            {
              if (overdue)
                table.setCellFg (row, 3, Text::red);
              else if (imminent)
                table.setCellFg (row, 3, Text::yellow);
            }
          }
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No matches."
              << std::endl;

/*
  if (gcCount)
    std::cout << std::endl
              << "[gc: "
              << gcCount
              << " transferred]"
              << std::endl;
*/
}

////////////////////////////////////////////////////////////////////////////////
// Year Month    Added Completed Deleted
// 2006 November    87        63      14
// 2006 December    21         6       1
time_t monthlyEpoch (const std::string& date)
{
  // Convert any date in epoch form to m/d/y, then convert back
  // to epoch form for the date m/1/y.
  if (date.length ())
  {
    Date d1 (::atoi (date.c_str ()));
    int m, d, y;
    d1.toMDY (m, d, y);
    Date d2 (m, 1, y);
    time_t epoch;
    d2.toEpoch (epoch);
    return epoch;
  }

  return 0;
}

void handleReportHistory (const TDB& tdb, T& task, Config& conf)
{
  std::map <time_t, int> groups;
  std::map <time_t, int> addedGroup;
  std::map <time_t, int> completedGroup;
  std::map <time_t, int> deletedGroup;

  // Scan the pending tasks.
  std::vector <T> pending;
  tdb.allPendingT (pending);
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    T task (pending[i]);
    time_t epoch = monthlyEpoch (task.getAttribute ("entry"));
    if (epoch)
    {
      groups[epoch] = 0;

      if (addedGroup.find (epoch) != addedGroup.end ())
        addedGroup[epoch] = addedGroup[epoch] + 1;
      else
        addedGroup[epoch] = 1;

      if (task.getStatus () == T::deleted)
      {
        epoch = monthlyEpoch (task.getAttribute ("end"));

        if (deletedGroup.find (epoch) != deletedGroup.end ())
          deletedGroup[epoch] = deletedGroup[epoch] + 1;
        else
          deletedGroup[epoch] = 1;
      }
      else if (task.getStatus () == T::completed)
      {
        epoch = monthlyEpoch (task.getAttribute ("end"));

        if (completedGroup.find (epoch) != completedGroup.end ())
          completedGroup[epoch] = completedGroup[epoch] + 1;
        else
          completedGroup[epoch] = 1;
      }
    }
  }

  // Scan the completed tasks.
  std::vector <T> completed;
  tdb.allCompletedT (completed);
  for (unsigned int i = 0; i < completed.size (); ++i)
  {
    T task (completed[i]);
    time_t epoch = monthlyEpoch (task.getAttribute ("entry"));
    if (epoch)
    {
      groups[epoch] = 0;

      if (addedGroup.find (epoch) != addedGroup.end ())
        addedGroup[epoch] = addedGroup[epoch] + 1;
      else
        addedGroup[epoch] = 1;

      epoch = monthlyEpoch (task.getAttribute ("end"));
      if (task.getStatus () == T::deleted)
      {
        epoch = monthlyEpoch (task.getAttribute ("end"));

        if (deletedGroup.find (epoch) != deletedGroup.end ())
          deletedGroup[epoch] = deletedGroup[epoch] + 1;
        else
          deletedGroup[epoch] = 1;
      }
      else if (task.getStatus () == T::completed)
      {
        epoch = monthlyEpoch (task.getAttribute ("end"));
        if (completedGroup.find (epoch) != completedGroup.end ())
          completedGroup[epoch] = completedGroup[epoch] + 1;
        else
          completedGroup[epoch] = 1;
      }
    }
  }

  // Now build the table.
  Table table;
  table.addColumn ("Year");
  table.addColumn ("Month");
  table.addColumn ("Added");
  table.addColumn ("Completed");
  table.addColumn ("Deleted");
  table.addColumn ("Net");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);
  table.setColumnUnderline (5);

  table.setColumnJustification (2, Table::right);
  table.setColumnJustification (3, Table::right);
  table.setColumnJustification (4, Table::right);
  table.setColumnJustification (5, Table::right);

  char *months[] =
  {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December",
  };

  int priorYear = 0;
  foreach (i, groups)
  {
    int row = table.addRow ();

    Date dt (i->first);
    int m, d, y;
    dt.toMDY (m, d, y);

    if (y != priorYear)
    {
      table.addCell (row, 0, y);
      priorYear = y;
    }
    table.addCell (row, 1, months[m - 1]);

    int net = 0;

    if (addedGroup.find (i->first) != addedGroup.end ())
    {
      table.addCell (row, 2, addedGroup[i->first]);
      net +=addedGroup[i->first];
    }

    if (completedGroup.find (i->first) != completedGroup.end ())
    {
      table.addCell (row, 3, completedGroup[i->first]);
      net -= completedGroup[i->first];
    }

    if (deletedGroup.find (i->first) != deletedGroup.end ())
    {
      table.addCell (row, 4, deletedGroup[i->first]);
      net -= deletedGroup[i->first];
    }

    table.addCell (row, 5, net);
    if (conf.get ("color", true) && net)
      table.setCellFg (row, 5, net > 0 ? Text::red: Text::green);
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl;
  else
    std::cout << "No tasks." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// A summary of the command usage.  Not useful to users, but used to display
// usage statistics for feedback.
//
// 2006-12-04 19:59:43 "task list"
//
void handleReportUsage (const TDB& tdb, T& task, Config& conf)
{
  if (conf.get ("command.logging") == "on")
  {
    std::map <std::string, int> usage;
    std::vector <std::string> all;
    tdb.logRead (all);
    for (unsigned int i = 0; i < all.size (); ++i)
    {
      // 0123456789012345678901
      //                      v 21
      // 2006-12-04 19:59:43 "task list"
      std::string command = all[i].substr (21, all[i].length () - 22);

      // Parse as a command line.
      std::vector <std::string> args;
      split (args, command, " ");

      try
      {
        T task;
        std::string commandName;
        parse (args, commandName, task);

        usage[commandName]++;
      }

      // Deliberately ignore errors from parsing the command log, as there may
      // be commands from a prior version of task in there, which were
      // abbreviated, and are now ambiguous.
      catch (...) {}
    }

    // Now render the table.
    Table table;
    table.addColumn ("Command");
    table.addColumn ("Frequency");
    table.setColumnUnderline (0);
    table.setColumnUnderline (1);
    table.setColumnJustification (1, Table::right);
    table.sortOn (1, Table::descendingNumeric);

    foreach (i, usage)
    {
      int row = table.addRow ();
      table.addCell (row, 0, (i->first == "" ? "(modify)" : i->first));
      table.addCell (row, 1, i->second);
    }

    if (table.rowCount ())
      std::cout << std::endl
                << table.render ()
                << std::endl;
    else
      std::cout << "No usage." << std::endl;
  }
  else
    std::cout << "Command logging is not enabled, so no history has been kept."
              << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void handleReportCalendar (const TDB& tdb, T& task, Config& conf)
{
  // Today.
  Date date;
  int m     = date.month ();
  int y     = date.year ();
  int today = date.day ();

  // Read all the tasks, filter by those that have a due date.
  std::vector <int> annotations;
  std::vector <T> pending;
  tdb.pendingT (pending);
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    T task (pending[i]);
    if (task.getAttribute ("due") != "")
    {
      Date d (::atoi (task.getAttribute ("due").c_str ()));
      if (d.year () == y && d.month () == m)
        annotations.push_back (d.day ());
    }
  }

  pending.clear ();

  Table table;
  table.addColumn ("Su");
  table.addColumn ("Mo");
  table.addColumn ("Tu");
  table.addColumn ("We");
  table.addColumn ("Th");
  table.addColumn ("Fr");
  table.addColumn ("Sa");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);
  table.setColumnUnderline (5);
  table.setColumnUnderline (6);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (1, Table::right);
  table.setColumnJustification (2, Table::right);
  table.setColumnJustification (3, Table::right);
  table.setColumnJustification (4, Table::right);
  table.setColumnJustification (5, Table::right);
  table.setColumnJustification (6, Table::right);

  int days = Date::daysInMonth (m, y);
  int row = table.addRow ();
  for (int d = 1; d <= days; ++d)
  {
    Date temp (m, d, y);
    int dow = temp.dayOfWeek ();

    table.addCell (row, dow, d);

    if (conf.get ("color", true) && d == today)
      table.setCellFg (row, dow, Text::cyan);

    for (unsigned int a = 0; a < annotations.size (); ++a)
    {
      if (conf.get ("color", true) && annotations[a] == d)
      {
        table.setCellFg (row, dow, Text::black);
        table.setCellBg (row, dow, d < today ? Text::red : Text::yellow);
      }
    }

    if (dow == 6 && d < days)
      row = table.addRow ();
  }

  std::cout << std::endl
            << Date::monthName (m)
            << " "
            << y
            << std::endl
            << std::endl
            << table.render ()
            << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void handleReportActive (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  // Get all the tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("ID");
  table.addColumn ("Project");
  table.addColumn ("Pri");
  table.addColumn ("Due");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::minimum);
  table.setColumnWidth (3, Table::minimum);
  table.setColumnWidth (4, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (3, Table::right);

  table.sortOn (3, Table::ascendingDate);
  table.sortOn (2, Table::descendingPriority);
  table.sortOn (1, Table::ascendingCharacter);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  // Iterate over each task, and apply selection criteria.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);
    if (refTask.getAttribute ("start") != "")
    {
      bool imminent = false;
      bool overdue = false;
      std::string due = refTask.getAttribute ("due");
      if (due.length () && due.find ("/") == std::string::npos)
      {
        Date dt (::atoi (due.c_str ()));
        int m, d, y;
        dt.toMDY (m, d, y);
        char formatted[12];
        sprintf (formatted, "%d/%d/%04d", m, d, y);
        due = formatted;

        Date now;
        overdue = dt < now ? true : false;
        now += 7 * 86400;
        imminent = dt < now ? true : false;
      }

      // All criteria match, so add refTask to the output table.
      int row = table.addRow ();
      table.addCell (row, 0, refTask.getId ());
      table.addCell (row, 1, refTask.getAttribute ("project"));
      table.addCell (row, 2, refTask.getAttribute ("priority"));
      table.addCell (row, 3, due);
      table.addCell (row, 4, refTask.getDescription ());

      if (conf.get ("color", true))
      {
        Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
        Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
        autoColorize (refTask, fg, bg);
        table.setRowFg (row, fg);
        table.setRowBg (row, bg);

        if (fg == Text::nocolor)
        {
          if (overdue)
            table.setCellFg (row, 3, Text::red);
          else if (imminent)
            table.setCellFg (row, 3, Text::yellow);
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No active tasks." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void handleReportOverdue (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  // Get all the tasks.
  std::vector <T> tasks;
  tdb.pendingT (tasks);

  initializeColorRules (conf);

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("ID");
  table.addColumn ("Project");
  table.addColumn ("Pri");
  table.addColumn ("Due");
  table.addColumn ("Description");

  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnUnderline (2);
  table.setColumnUnderline (3);
  table.setColumnUnderline (4);

  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnWidth (2, Table::minimum);
  table.setColumnWidth (3, Table::minimum);
  table.setColumnWidth (4, Table::flexible);

  table.setColumnJustification (0, Table::right);
  table.setColumnJustification (3, Table::right);

  table.sortOn (3, Table::ascendingDate);
  table.sortOn (2, Table::descendingPriority);
  table.sortOn (1, Table::ascendingCharacter);

  // Split any description specified into words.
  std::vector <std::string> descWords;
  split (descWords, task.getDescription (), ' ');

  // Get all the tags to match against.
  std::vector <std::string> tagList;
  task.getTags (tagList);

  // Get all the attributes to match against.
  std::map <std::string, std::string> attrList;
  task.getAttributes (attrList);

  Date now;

  // Iterate over each task, and apply selection criteria.
  for (unsigned int i = 0; i < tasks.size (); ++i)
  {
    T refTask (tasks[i]);
    std::string due;
    if ((due = refTask.getAttribute ("due")) != "")
    {
      if (due.length () && due.find ("/") == std::string::npos)
      {
        Date dt (::atoi (due.c_str ()));
        int m, d, y;
        dt.toMDY (m, d, y);
        char formatted[12];
        sprintf (formatted, "%d/%d/%04d", m, d, y);
        due = formatted;

        // If overdue.
        if (dt < now)
        {
          // All criteria match, so add refTask to the output table.
          int row = table.addRow ();
          table.addCell (row, 0, refTask.getId ());
          table.addCell (row, 1, refTask.getAttribute ("project"));
          table.addCell (row, 2, refTask.getAttribute ("priority"));
          table.addCell (row, 3, due);
          table.addCell (row, 4, refTask.getDescription ());

          if (conf.get ("color", true))
          {
            Text::color fg = Text::colorCode (refTask.getAttribute ("fg"));
            Text::color bg = Text::colorCode (refTask.getAttribute ("bg"));
            autoColorize (refTask, fg, bg);
            table.setRowFg (row, fg);
            table.setRowBg (row, bg);

            if (fg == Text::nocolor)
              table.setCellFg (row, 3, Text::red);
          }
        }
      }
    }
  }

  if (table.rowCount ())
    std::cout << std::endl
              << table.render ()
              << std::endl
              << table.rowCount ()
              << (table.rowCount () == 1 ? " task" : " tasks")
              << std::endl;
  else
    std::cout << "No overdue tasks." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void handleReportStats (const TDB& tdb, T& task, Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  // Get all the tasks.
  std::vector <T> tasks;
  tdb.allT (tasks);

  Date now;
  time_t earliest   = time (NULL);
  time_t latest     = 1;
  int totalT        = 0;
  int deletedT      = 0;
  int pendingT      = 0;
  int completedT    = 0;
  int taggedT       = 0;
  float daysPending = 0.0;
  int descLength    = 0;

  std::vector <T>::iterator it;
  for (it = tasks.begin (); it != tasks.end (); ++it)
  {
    ++totalT;
    if (it->getStatus () == T::deleted)   ++deletedT;
    if (it->getStatus () == T::pending)   ++pendingT;
    if (it->getStatus () == T::completed) ++completedT;

    time_t entry = ::atoi (it->getAttribute ("entry").c_str ());
    if (entry < earliest) earliest = entry;
    if (entry > latest)   latest   = entry;

    if (it->getStatus () == T::completed)
    {
      time_t end = ::atoi (it->getAttribute ("end").c_str ());
      daysPending += (end - entry) / 86400.0;
    }

    if (it->getStatus () == T::pending)
      daysPending += (now - entry) / 86400.0;

    descLength += it->getDescription ().length ();

    std::vector <std::string> tags;
    it->getTags (tags);
    if (tags.size ()) ++taggedT;
  }

  // TODO Unused feature list

  std::cout << "Pending               " << pendingT   << std::endl
            << "Completed             " << completedT << std::endl
            << "Deleted               " << deletedT   << std::endl
            << "Total                 " << totalT     << std::endl;

  Date e (earliest);
  std::cout << "Oldest task           " << e.toString () << std::endl;
  Date l (latest);
  std::cout << "Newest task           " << l.toString () << std::endl;
  std::cout << "Task used for         " << formatSeconds (latest - earliest) << std::endl;

  if (totalT)
    std::cout << "Task added every      " << formatSeconds ((latest - earliest) / totalT)     << std::endl;

  if (completedT)
    std::cout << "Task completed every  " << formatSeconds ((latest - earliest) / completedT) << std::endl;

  if (deletedT)
    std::cout << "Task deleted every    " << formatSeconds ((latest - earliest) / deletedT)   << std::endl;

  if (pendingT || completedT)
    std::cout << "Average time pending  " << formatSeconds ((int) ((daysPending / (pendingT + completedT)) * 86400)) << std::endl;

  if (totalT)
  {
    std::cout << "Average desc length   " << (int) (descLength / totalT) << " characters" << std::endl;
    std::cout << "Tasks tagged          " << std::setprecision (3) << (100.0 * taggedT / totalT) << "%" << std::endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
void handleVersion (Config& conf)
{
  // Determine window size, and set table accordingly.
  int width = 80;
#ifdef HAVE_LIBNCURSES
  if (conf.get ("curses", true))
  {
    WINDOW* w = initscr ();
    width = w->_maxx + 1;
    endwin ();
  }
#endif

  // Handle case for zero width on mobile device.
  if (width == 0)
    width = 80;

  // Create a table for output.
  Table table;
  table.setTableWidth (width);
  table.addColumn ("Config variable");
  table.addColumn ("Value");
  table.setColumnUnderline (0);
  table.setColumnUnderline (1);
  table.setColumnWidth (0, Table::minimum);
  table.setColumnWidth (1, Table::minimum);
  table.setColumnJustification (0, Table::left);
  table.setColumnJustification (1, Table::left);
  table.sortOn (0, Table::ascendingCharacter);

  std::vector <std::string> all;
  conf.all (all);
  foreach (i, all)
  {
    std::string value = conf.get (*i);
    if (value != "")
    {
      int row = table.addRow ();
      table.addCell (row, 0, *i);
      table.addCell (row, 1, value);
    }
  }

  std::cout << "Copyright (C) 2006 - 2008 Paul Beckingham."
            << std::endl
            << PACKAGE
            << " "
            << VERSION
            << std::endl
            << std::endl
            << table.render ()
            << std::endl;

  // Verify installation.  This is mentioned in the documentation as the way to
  // ensure everything is properly installed.

  if (all.size () == 0)
    std::cout << "Configuration error: .taskrc contains no entries"
              << std::endl;
  else
  {
    if (conf.get ("data.location") == "")
      std::cout << "Configuration error: data.location not specified in .taskrc "
                   "file."
                << std::endl;

    if (access (conf.get ("data.location").c_str (), X_OK))
      std::cout << "Configuration error: data.location contains a directory name"
                   " that doesn't exist, or is unreadable."
                << std::endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
void handleDelete (const TDB& tdb, T& task, Config& conf)
{
  if (conf.get ("confirmation") != "yes" || confirm ("Permanently delete task?"))
    tdb.deleteT (task);
  else
    std::cout << "Task not deleted." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void handleStart (const TDB& tdb, T& task, Config& conf)
{
  std::vector <T> all;
  tdb.pendingT (all);

  std::vector <T>::iterator it;
  for (it = all.begin (); it != all.end (); ++it)
  {
    if (it->getId () == task.getId ())
    {
      T original (*it);

      if (original.getAttribute ("start") == "")
      {
        char startTime[16];
        sprintf (startTime, "%u", (unsigned int) time (NULL));
        original.setAttribute ("start", startTime);

        original.setId (task.getId ());
        tdb.modifyT (original);

        nag (tdb, task, conf);
        return;
      }
      else
        std::cout << "Task " << task.getId () << " already started." << std::endl;
    }
  }

  throw std::string ("Task not found.");
}

////////////////////////////////////////////////////////////////////////////////
void handleDone (const TDB& tdb, T& task, Config& conf)
{
  if (!tdb.completeT (task))
    throw std::string ("Could not mark task as completed.");

  nag (tdb, task, conf);
}

////////////////////////////////////////////////////////////////////////////////
void handleExport (const TDB& tdb, T& task, Config& conf)
{
  std::string file = trim (task.getDescription ());

  std::ofstream out (file.c_str ());
  if (out.good ())
  {
    out << "'id',"
        << "'status',"
        << "'tags',"
        << "'entry',"
        << "'start',"
        << "'due',"
        << "'end',"
        << "'project',"
        << "'priority',"
        << "'fg',"
        << "'bg',"
        << "'description'"
        << "\n";

    std::vector <T> all;
    tdb.allT (all);
    foreach (t, all)
    {
      out << t->composeCSV ().c_str ();
    }
    out.close ();
  }
  else
    throw std::string ("Could not write to export file.");
}

////////////////////////////////////////////////////////////////////////////////
void handleModify (const TDB& tdb, T& task, Config& conf)
{
  std::vector <T> all;
  tdb.pendingT (all);

  std::vector <T>::iterator it;
  for (it = all.begin (); it != all.end (); ++it)
  {
    if (it->getId () == task.getId ())
    {
      T original (*it);

      // A non-zero value forces a file write.
      int changes = 0;

      // Apply a new description, if any.
      if (task.getDescription () != "")
      {
        original.setDescription (task.getDescription ());
        ++changes;
      }

      // Apply or remove tags, if any.
      std::vector <std::string> tags;
      task.getTags (tags);
      for (unsigned int i = 0; i < tags.size (); ++i)
      {
        if (tags[i][0] == '+')
          original.addTag (tags[i].substr (1, std::string::npos));
        else
          original.addTag (tags[i]);

        ++changes;
      }

      task.getRemoveTags (tags);
      for (unsigned int i = 0; i < tags.size (); ++i)
      {
        if (tags[i][0] == '-')
          original.removeTag (tags[i].substr (1, std::string::npos));
        else
          original.removeTag (tags[i]);

        ++changes;
      }

      // Apply or remove attributes, if any.
      std::map <std::string, std::string> attributes;
      task.getAttributes (attributes);
      foreach (i, attributes)
      {
        if (i->second == "")
          original.removeAttribute (i->first);
        else
          original.setAttribute (i->first, i->second);

        ++changes;
      }

      std::string from;
      std::string to;
      task.getSubstitution (from, to);
      if (from != "")
      {
        std::string description = original.getDescription ();
        unsigned int pattern = description.find (from);
        if (pattern != std::string::npos)
        {
          description = description.substr (0, pattern) +
                        to                              +
                        description.substr (pattern + from.length (), std::string::npos);
          original.setDescription (description);
          ++changes;
        }
      }

      if (changes)
      {
        original.setId (task.getId ());
        tdb.modifyT (original);
      }

      return;
    }
  }

  throw std::string ("Task not found.");
}

////////////////////////////////////////////////////////////////////////////////
void gatherNextTasks (
  const TDB& tdb,
  T& task,
  Config& conf,
  std::vector <T>& pending,
  std::vector <int>& all)
{
  // For counting tasks by project.
  std::map <std::string, int> countByProject;
  std::map <int, bool> matching;

  Date now;

  // How many items per project?  Default 3.
  int limit = conf.get ("next", 3);

  // due:< 1wk, pri:*
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string due = pending[i].getAttribute ("due");
      if (due != "")
      {
        Date d (::atoi (due.c_str ()));
        if (d < now + (7 * 24 * 60 * 60)) // if due:< 1wk
        {
          std::string project = pending[i].getAttribute ("project");
          if (countByProject[project] < limit && matching.find (i) == matching.end ())
          {
            ++countByProject[project];
            matching[i] = true;
          }
        }
      }
    }
  }

  // due:*, pri:H
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string due = pending[i].getAttribute ("due");
      if (due != "")
      {
        std::string priority = pending[i].getAttribute ("priority");
        if (priority == "H")
        {
          std::string project = pending[i].getAttribute ("project");
          if (countByProject[project] < limit && matching.find (i) == matching.end ())
          {
            ++countByProject[project];
            matching[i] = true;
          }
        }
      }
    }
  }

  // pri:H
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string priority = pending[i].getAttribute ("priority");
      if (priority == "H")
      {
        std::string project = pending[i].getAttribute ("project");
        if (countByProject[project] < limit && matching.find (i) == matching.end ())
        {
          ++countByProject[project];
          matching[i] = true;
        }
      }
    }
  }

  // due:*, pri:M
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string due = pending[i].getAttribute ("due");
      if (due != "")
      {
        std::string priority = pending[i].getAttribute ("priority");
        if (priority == "M")
        {
          std::string project = pending[i].getAttribute ("project");
          if (countByProject[project] < limit && matching.find (i) == matching.end ())
          {
            ++countByProject[project];
            matching[i] = true;
          }
        }
      }
    }
  }

  // pri:M
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string priority = pending[i].getAttribute ("priority");
      if (priority == "M")
      {
        std::string project = pending[i].getAttribute ("project");
        if (countByProject[project] < limit && matching.find (i) == matching.end ())
        {
          ++countByProject[project];
          matching[i] = true;
        }
      }
    }
  }

  // due:*, pri:L
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string due = pending[i].getAttribute ("due");
      if (due != "")
      {
        std::string priority = pending[i].getAttribute ("priority");
        if (priority == "L")
        {
          std::string project = pending[i].getAttribute ("project");
          if (countByProject[project] < limit && matching.find (i) == matching.end ())
          {
            ++countByProject[project];
            matching[i] = true;
          }
        }
      }
    }
  }

  // pri:L
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string priority = pending[i].getAttribute ("priority");
      if (priority == "L")
      {
        std::string project = pending[i].getAttribute ("project");
        if (countByProject[project] < limit && matching.find (i) == matching.end ())
        {
          ++countByProject[project];
          matching[i] = true;
        }
      }
    }
  }

  // due:, pri:
  for (unsigned int i = 0; i < pending.size (); ++i)
  {
    if (pending[i].getStatus () == T::pending)
    {
      std::string due = pending[i].getAttribute ("due");
      if (due == "")
      {
        std::string priority = pending[i].getAttribute ("priority");
        if (priority == "")
        {
          std::string project = pending[i].getAttribute ("project");
          if (countByProject[project] < limit && matching.find (i) == matching.end ())
          {
            ++countByProject[project];
            matching[i] = true;
          }
        }
      }
    }
  }

  // Convert map to vector.
  foreach (i, matching)
    all.push_back (i->first);
}

////////////////////////////////////////////////////////////////////////////////
void nag (const TDB& tdb, T& task, Config& conf)
{
  std::string nagMessage = conf.get ("nag", std::string (""));
  if (nagMessage != "")
  {
    // Load all pending.
    std::vector <T> pending;
    tdb.allPendingT (pending);

    // Restrict to matching subset.
    std::vector <int> matching;
    gatherNextTasks (tdb, task, conf, pending, matching);

    foreach (i, matching)
      if (pending[*i].getId () == task.getId ())
        return;

    std::cout << nagMessage << std::endl;
  }
}

////////////////////////////////////////////////////////////////////////////////

