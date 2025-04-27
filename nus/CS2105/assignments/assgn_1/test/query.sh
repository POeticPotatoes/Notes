#!/bin/bash

d0="$(dirname "$(readlink -f -- "$0")")"

py38="/usr/bin/python3"

"$py38" -c "import cquery" "$1"

