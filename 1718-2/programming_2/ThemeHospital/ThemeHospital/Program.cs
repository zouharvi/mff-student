using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace ThemeHospital
{

    class Program
    {
        static void Main(string[] args)
        {
            HospitalGraph graph = Parser.Parse("11\nENTRANCE-1 <--(5)--> INFODESK-2\nINFODESK-2 <--(5)--> GP-3\nINFODESK-2 <--(10)--> GP-4\nGP-4 <--(5)--> TREATMENT-5\nTREATMENT-5 <--(5)--> ENTRANCE-2\nGP-4 --(30)--> EEG-6\nEEG-6 --(10)--> GP-4\nGP-4 <--(3)--> EEG-6\nEEG-6 <--(10)--> SONO-7\nEEG-6 <--(10)--> XRAY-8\nEEG-6 <--(10)--> PSYCHO-9\n12\nHynek:1:NEUROTIC\nVilem:1:PNEUMONIA\nJarmila:3:HIP-PAIN\nPepa:6:CARDIAC\nJan:2:PNEUMONIA\nDavid:2:CARDIAC\nEma:4:HIP-PAIN\nIda:1:NEUROTIC\nOtakar:5:HIP-PAIN\nLukas:3:CARDIAC\nOndrej:2:PNEUMONIA\nJiri:2:PNEUMONIA\n12");
            Console.ReadLine();
        }
    }
}
