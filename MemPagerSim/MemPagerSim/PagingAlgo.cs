// patrick.haren@yahoo.com

using System;

/* 
 * PagingAlgo is a generic class that contains the representation of
 * the memory system and the functions needed for an algorithm simulation
 */

namespace MemPagerSim
{
    abstract public class PagingAlgo
    {
        protected int[] pagesInFrames;                  // each frame holds a page

        // base constructor
        public PagingAlgo(int numFrames)
        {
            pagesInFrames = new int[numFrames];
            for (int i = 0; i < numFrames; i++)
                pagesInFrames[i] = -1;          // represents empty
        }

        // state of pageframe
        public int[] currentFrames()
        {
            return pagesInFrames;
        }

        // header info about the algo
        public String about()
        {
            return description() + " algorithm with " + pagesInFrames.Length + " frames";
        }

        // common helper method (name speaks for itself)
        protected bool havePage(int testPage)
        {
            foreach (int page in pagesInFrames)
                if (page == testPage)
                    return true;
            return false;
        }

        /* -------------------------------------------------------------------
         * method to be implemented by specific algorithms 
         * algorithm handles the request for a page
         * if the page is already in the frame, return true
         * if the page had to be swapped in (page fault), return false 
         */
        public abstract bool takePageRequest(int page);

        protected abstract String description();
    }
}