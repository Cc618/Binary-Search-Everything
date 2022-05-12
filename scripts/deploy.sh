#!/bin/sh

# Deploy web content within the public folder
# To be run from the root of the repository

set -e

rm -rf public
cp -r web public

# Parse exercises
echo "<ul>" > public/summary.html
for exo in exercises/*.md; do
    name="$(basename "${exo%.md}")"
    scripts/gen_problem.py "$name"
    echo "> $name"
done
echo "</ul>" >> public/summary.html

# Replace index special variables (summary...)
scripts/replace_specials.py

# Copy full solutions
mkdir -p public/solutions
cp solutions/*.cpp public/solutions

# Clean
rm public/summary.html
rm public/template.html

echo Deployed
