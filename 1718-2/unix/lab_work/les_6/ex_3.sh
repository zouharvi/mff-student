#!/bin/bash

find . -name "*.jpg" -exec sh -c "echo {} | sed 's/.jpg$/.JPG/' | xargs mv {}" \;
