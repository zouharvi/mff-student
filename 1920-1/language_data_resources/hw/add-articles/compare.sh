#!/usr/bin/bash

# cat pred.conllu | grep '# text = '  | sed 's/# text = //g' > tmp_0
cat sample/gold.conllu | grep '# text = ' | sed 's/# text = //g' > tmp_1
diff tmp_{3,1}
# rm tmp_{0,1}