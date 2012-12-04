// patrick.haren@yahoo.com

using System;

/*
 * Simple implementation of the OPT page request handler algorithm
 */
namespace MemPagerSim
{
    class OptimalPaging : PagingAlgo
    {
        // the crystal ball
        int[] sequence;
        int step;

        /* 
         * constructor recieves the full sequence
         */ 
        public OptimalPaging(int size, int[] seq) : base(size)
        {
            sequence = seq;
            step = -1;
        }

        // blurb
        protected override String description()
        {
            return "OPT | Optimal";
        }

        // ----- Replace the page that will not be used for the longest period of time
        public override bool takePageRequest(int page /* like we didn't already know */)
        {
            step++; // track next in the sequence
            if (havePage(page)) return true;

            int bestFrame = 0;
            if (step < pagesInFrames.Length)                // still space for more pages
            {
                bestFrame = step;
            }
            else                                            // all full => time to fault and kick out a page
            {
                int longestSoFar = -1;

                // foreach(int page in pagesInFrames)
                for (int frame = 0; (frame < pagesInFrames.Length) && (longestSoFar != int.MaxValue); frame++)
                {
                    int seerTimeSlot = findInFuture(sequence, step, pagesInFrames[frame]);
                    if (seerTimeSlot > longestSoFar)
                    {
                        longestSoFar = seerTimeSlot;
                        bestFrame = frame;
                    }
                }
            }

            pagesInFrames[bestFrame] = page;    // accomodate the page
            return false;                       // had a page fault
        }

        // helper function - returns the next position of the specified value in array, from start, if any
        private int findInFuture(int[] array, int start, int value)
        {
            int pos = int.MaxValue;
            for (int i = start; (i<array.Length) && (pos==int.MaxValue); i++)
                if (array[i] == value)
                    pos = i;
            return pos;
        }
    }
}
