#!/bin/sh

# Generates a problem page from its name

if [ "$#" != 1 ]; then
    echo "usage: $0 <problem-name>" >&2
    exit 1
fi

name="$1"
content="<html><body> <h1>$name</h1> <h2><a href=\"../exercises/$name.html\">Statement</a></h2> <h2><a href=\"../solutions/$name.html\">Solution</a></h2> <h2><a href=\"../solutions/$name.cpp\">Solution code</a></h2> </body></html>"

echo "$content" > public/problems/"$name".html

# TODO : Generate summary
echo "<li><a href=\"problems/$name.html\">$name</a></li>" >> public/summary.html

echo "Generated problem '$name'"
