#!/bin/sh

# Deploy web content within the public folder
# To be run from the root of the repository

set -e

rm -rf public
cp -r web public

mkdir public/problems

echo "<ul>" > public/summary.html
for exo in exercises/*.md; do
    name="$(basename "${exo%.md}")"
    scripts/gen_problem.py "$name"
    echo "> $name"
done
echo "</ul>" >> public/summary.html

scripts/replace_specials.py

# TODO : Markdown...
# mkdir public/{exercises,solutions}
cp -r exercises public
cp -r solutions public

echo Deployed
