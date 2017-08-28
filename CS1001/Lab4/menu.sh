#!/bin/bash

menu() {
  CHOICE=""
  for file in *; do
    echo "v) View File $file"
    echo "e) Edit File $file"
    echo "c) Compile File $file"
    echo "q) Quit"
    read CHOICE
    if [[ $CHOICE == 'v' ]]; then
      less $file
    elif [[ $CHOICE == 'e' ]]; then
      jpico $file
    elif [[ $CHOICE == 'c' ]]; then
      g++ $file
    elif [[ $CHOICE == 'q' ]]; then
      exit
    else
      echo "INVALID RESPONSE"
      echo ""
      echo "Skipping this file!"
    fi  
    echo ""  
  done
}
menu
