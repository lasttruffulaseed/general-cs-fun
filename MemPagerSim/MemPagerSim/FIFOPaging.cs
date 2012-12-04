// patrick.haren@yahoo.com

using System;

/*
 * Simple implementation of the FIFO page request handler algorithm
 */
namespace MemPagerSim
{
    class FIFOPaging : PagingAlgo
    {
        // no need for an actual fifo - just use pagesinframe and position
        int ptr;

        public FIFOPaging(int size) : base(size) 
        {
            ptr = 0;
        }

        // blurb
        protected override String description()
        {
            return "FIFO | First In First Out";
        }

        // ----- replace the page that is oldest
        public override bool takePageRequest(int page)
        {
            if (havePage(page)) return true;

            // fault
            pagesInFrames[(ptr++ % pagesInFrames.Length)] = page;
            return false;
        }
    }
}
