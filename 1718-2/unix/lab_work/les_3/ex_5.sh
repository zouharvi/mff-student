#!/bin/bash

getent passwd | cut -d: -f "5" | sort | uniq -d
