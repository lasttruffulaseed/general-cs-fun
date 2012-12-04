// patrick.haren@yahoo.com

using System;
using System.Collections.Generic;
using System.Text;

/* 
 * PagingSequencer drives an algorithm through its paces
 * Along the way, it captures the frame states, for display
 */ 
namespace MemPagerSim
{
    class PagingSequencer
    {
        PagingAlgo algo;
        int[] sequence;
        bool repeatsAsBlank;

        /*
         * Constructor - extract the algo type, frame-size and sequence from the specification string
         */
        public PagingSequencer(String specLine, bool repeatsAsBlank)
        {
            String[] components = specLine.Split(',');
            this.repeatsAsBlank = repeatsAsBlank;

            if (components.Length < 2) return;

            // algorithm code
            String algoCode = components[0];

            try
            {
                // framesize
                int frameSize = int.Parse(components[1]);

                // sequence
                sequence = new int[components.Length - 2];
                for (int i = 2; i < components.Length; i++)
                    sequence[i - 2] = int.Parse(components[i]);

                // prepare the algorithm
                switch (algoCode.ToLower())
                {
                    case "f":
                        algo = new FIFOPaging(frameSize);
                        break;
                    case "l":
                        algo = new LRUPaging(frameSize);
                        break;
                    case "o":
                        algo = new OptimalPaging(frameSize, sequence);
                        break;
                }
            }
            catch (Exception) {/*eat => algo will be null */}
        }

        /*
         * run the algorithm, collecting a report of the results
         */
        public String runAsHtmlReport(bool topToBottom)
        {
            // report pre-amble
            StringBuilder report = new StringBuilder();

            // quick exit. if something's not right
            if (algo == null)
            {
                report.Append("<p>reference text is not recognizable. please take a look and see...</p><br />");
                return report.ToString();
            }

            // report header (showing the steps at top)
            report.Append("<p>Running " + algo.about() + "</p>");
            report.Append("<table><tr>");
            for (int step = 0; step < sequence.Length; step++)
                report.Append("<td>" + sequence[step] + "</td>");
            report.Append("</tr><tr>");

            // --- run the steps

            int faults = 0;
            for (int step = 0; step < sequence.Length; step++)
            {
                // run the step
                if (!algo.takePageRequest(sequence[step]))
                {
                    faults++;
                }
                else if (repeatsAsBlank)
                {
                    report.Append("<td></td>");
                    continue;
                }

                // get the state of frames
                int[] pageFrames = algo.currentFrames();

                // report on the state for this step
                report.Append("<td><table>");
                foreach(int page in pageFrames)
                    report.Append("<tr><td></td><td class=\"bf\">" + (page==-1 ? ".." : ""+page) + "</td></tr>");
                report.Append("</table></td>");
            }

            // report end
            report.Append("</tr></table>");
            report.Append("<p>This algorithm encountered a total of " + faults + " page faults</p><hr />");

            return report.ToString();
        }
    }
}
