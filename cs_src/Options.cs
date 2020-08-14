using System;
using System.Collections.Generic;
using System.Text;

namespace smake
{
    static class Options
    {
        // direct translation of python/rust code; would have proper config. support otherwise

        public const string F_STOPWORDS = "./data/stopwords.txt";

        public const string G_ABSTR_DIR = "./data/hulth2003_all/";
        public const string G_ABSTR_PATTERN = "*.abstr";

        public const bool PRINT_RESULTS = true;

        public const int CONSIDERED_RESULTS = 15;
        public const float LENGTH_POWER = 0.16f;
        public const float DUPLICITY_SCORE = -0.8f;
    }
}
