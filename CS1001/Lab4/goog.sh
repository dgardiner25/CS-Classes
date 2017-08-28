#!/bin/bash

search() {
  FIND="$1"
  URL="$2"
  COUNT=0
  
  if [[ $# != 2 ]]; then
    echo "Correct Usage: bash goog.sh [word to find] [URL]" 
  else { 
    COUNT=$(wget --quiet -O - "$URL" | tr " " "\n" | grep -c "$FIND")
    echo "$FIND: $COUNT"
  }
  fi
}

search "$@"
