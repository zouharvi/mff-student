#!/usr/bin/env bash

cat sample/UD_Czech/*.conllu | udapy -q .NounClusters
