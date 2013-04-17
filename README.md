general-cs-fun
==============

Fun projects in the art and science of computing<br>
patrick.haren@yahoo.com

MemPagerSim
-----------
<br>
The textbook <a href="http://www.wiley.com/WileyCDA/WileyTitle/productCd-EHEP000141.html">Operating System Concepts, 8th
edition</a> by Silberschatz, Galvin and Gagne, describes various strategies for page replacement in virtual memory systems. 
<br>
This c# app implements a trivial framework and UI for simulating such strategies. It includes examples for FIFO, Optimal 
and LRU page replacement algorithms. The app takes a sequence string, similar to the strings described in the text, that 
describe the algorithm to use, the simulated number of frames and the sequence of page requests to be simulated.
<h4>Fun Features!</h4>
1) An extensible class framework to allow additional algorithms to be plugged in.
<br>
2) Use of abstract methods/callbacks for the extension points.
<br>
3) Use of an embedded browser control for 'pretty printing' of the simulation. This is a similar implementation pattern to
   what is used within multi-platform mobile applications - whereby the rendering leverages existing capabilities of a 
   native browser.
<br>   
See slides 9.25 to 9.31, in ch9_1.pdf, for a description of the FIFO and Optimal page replacement strategies. The Optimal
strategy requires an advanced "crystal ball processor unit", with properties similar to a 
<a href="http://en.wikipedia.org/wiki/DeLorean_time_machine#Flux_capacitor">flux capacitor</a>. We're simulating its
immense capabilities here by providing the request sequence in advance to the algorithm...
Also, slides 9.4 to 9.8, in ch9_2.pdf, describe the LRU page replacement strategy.
The 'pretty printed' output is formatted to look the same as in the examples in the text - with the sequence of frames
moving horizontally across the page.
<br>Perhaps the app could be used to produce more examples in later additions of the text... ;)

Monopoly-Simulator
-------- ---------
<br>
This is a c++ console app (on purpose), which includes the rules for the game of monopoly, for simulating random games.
<br>
It was an exercise to flex the use of multiple-inheritence, polymorphism and dynamic dispatches of many types.
