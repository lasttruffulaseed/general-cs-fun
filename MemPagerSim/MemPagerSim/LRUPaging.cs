// patrick.haren@yahoo.com

using System;
using System.Collections.Generic;

/*
 * Simple implementation of the LRU page request handler algorithm
 */
namespace MemPagerSim
{
    class LRUPaging : PagingAlgo
    {
        int step;
        LinkedList<int> pagePile;   // keeps the most active pages on top of the rest

        public LRUPaging(int size) : base(size) 
        {
            step = -1;
            pagePile = new LinkedList<int>();
        }

        // blurb
        protected override String description()
        {
            return "LRU | Least Recently Used";
        }

        // ----- Replace the page that was used least recently
        public override bool takePageRequest(int page)
        {
            step++;
            LinkedListNode<int> pageNode = pagePile.Find(page);

            if (pageNode != null)               // have page
            {
                // just accessed => place as most recently used                
                pagePile.Remove(pageNode);
                pagePile.AddFirst(pageNode);
                return true;
            }

            // find out which page drew the short straw
            int f;  // frame to use
            if (pagePile.Count < pagesInFrames.Length)
            {
                // use next empty frame (note: would be more involved, with requests for page removals)
                f = pagePile.Count;     
            }
            else
            {
                LinkedListNode<int> lruPageNode = pagePile.Last;
                int lruPage = lruPageNode.Value;

                // remove it from the pile (sorry only so much room)
                pagePile.RemoveLast();

                // a plain table scan to match frame
                // [could have stored frame with page in the linked list, as alternative]
                for (f = 0; f < pagesInFrames.Length; f++)
                    if (pagesInFrames[f] == lruPage)
                        break;
            }

            // replace page in the lru frame with new page
            pagesInFrames[f] = page;
            pagePile.AddFirst(page);

            return false;               // had a fault
        }
    }
}
