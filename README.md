# Day 7 Redux
### Advent of Code 2017

This is a one-year-later revisit to one of my toughest days in 2017's AoC challenge. Along with updating my solution I will be using this repo to experiment with CMake and Catch2.

## The Challenge
A recursive algorithm has run amok resulting in a tower of unstable programs. Each program is struggling to balance a varying number of child-programs while they, in turn, attempt to balance on top of their parent. At the bottom of this tower is a single program attempting to keep the whole structure from collapsing.

Part 1: Given a data set of program names, weights, and their children (if any) find the name of the tower's base program.

Part 2: For a program to be balanced all of it's child programs must be balanced (equally weighted). There is a single program who's weight is throwing off the entier tower, preventing the programs from returning. What must that single program's weight be changed to?

## Original Attempt
This was the only challenge to take me longer than a day to complete. At the time I was somewhere around Chapter 15 or so in the Stroustrup book, well before pointers, containers and algorithms. I had to read ahead and try to figure out how these things worked to implement what I viewed as a "fat linked-list".

The result was a solution that crashed spectacularly; a recursive call aborted the program with a max vector size exception. When I posted my error message on the Cpp Slack channel there were users who were astounded at the magnitude of my failure. Not really though. There was help that I got from a user. Looking back at my solution, I have to appreciate that a seasoned C++ programmer was kind enough to wade through my half-baked use of language features.

In the end, a day or two later I was able to partially solve the part 2 problem. I was able to narrow down the range of where my unbalanced program was in the tower and print out the nearest parents and children. I then shamefully broke out a calculator and did the math for myself. My solution passed and I was onto the next day's challenges.

## A Year Later...
So it's November and AoC 2018 is almost upon us. In anticipation of the new challenges I decided to go back and re-work my solution, this time with a year's worth of experience with C++ and better overall programming practices. Right away I realized I was dealing with more of an N-ary Tree than a Linked-list with extra links. I was able to achieve a "better" solution and actually dial in my output to tell me exactly the information that was needed.

This first "redux" is in my advent2017 repository along side my original solution.

I didn't feel like I had actually completed anything, however. My original run through the challenges ended up being a cornucopia of learning and good feelings. Though I was proud to have slain my dragon, I was missing that feeling of accomplishment I had experienced every day last December.

I needed to take it further.

## What kind of magic spell to use?
Building and testing are high on my list of to-learn's these days. I had experimented with CMake and Catch2 previously but my results were less than satisfactory. I wasn't doing something right. My builds took forever and something was causing CLion to lag so bad it became unusable. Naturally, I abandoned all three.

This seemed to be my opportunity to revisit these tools and learn how to use them correctly.

## Project Complete
I broke up the mono file into smaller files and classes then learned to build everything as libs and link them to the executables instead of compiling everything twice. I wrote tests. I found bugs later that previous tests should have caught and learned how to write better, more complete tests.

I'm sure there's improvements that could be made here but I'm happy with what I have accomplished and look forward to the next project.

### Contributions are Welcome!
In an effort to learn even more I will  be sharing this repo around. If there are suggestions for how I could improve my testing or build process please open an issue and let me know.
