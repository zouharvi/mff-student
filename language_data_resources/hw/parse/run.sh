#!/usr/bin/env bash

udapy read.Conllu zone=gold files=sample.conllu \
      read.Conllu zone=pred files=sample.conllu \
      transform.Flatten zones=pred \
      .Parse zones=pred \
      eval.Parsing gold_zone=gold \
      util.MarkDiff gold_zone=gold \
      write.TextModeTreesHtml marked_only=1 files=parse-diff.html
