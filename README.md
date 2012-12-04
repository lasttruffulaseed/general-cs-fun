general-cs-fun
==============

Fun projects in the art and science of computing
patrick.haren@yahoo.com

MemPagerSim
-----------
The textbook "Operating System Concepts, 8th edition" by Silberschatz, Galvin and Gagne, describes various strategies for
page replacement in virtual memory systems. This c# app implements a trivial framework and UI for simulating such
strategies. It includes examples for FIFO, Optimal and LRU page replacement algorithms. The app takes a sequence string,
similar to the strings described in the text, that describe the algorithm to use, the simulated number of frames and the
sequence of page requests to be simulated.
Fun features:
1) An extensible class framework to allow additional algorithms to be plugged in.
2) Use of abstract methods/callbacks for the extension points.
3) Use of an embedded browser control for 'pretty printing' of the simulation. This is a similar implementation pattern as
   used with multi-platform mobile applications - where the rendering leverages the existing capabilities of a native
   browser.
See slides 9.25 to 9.31, in ch9_1.pdf, for a description of the FIFO and Optimal page replacement strategies.
Also, slides 9.4 to 9.8, in ch9_2.pdf, describe the LRU page replacement strategy.
The 'pretty printed' output is formatted to look the same as in the examples in the text - with the sequence of frames
moving horizontally across the page. Perhaps the app could be used to produce more examples in later additions :)

