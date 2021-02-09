#! /bin/bash

echo "<!DOCTYPE html>"

echo "<html>"
echo "<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />"
echo "<h2><b>Table de 2</b></h2>"
echo "<table>"
echo "<thead><tr>"
echo "<td><b> x </b></td> "
echo "<td><b>2x</b></td> "
echo "</tr></thead>"
echo "<tbody>"
i=0
echo "<style type=\"text/css\">"
echo "td.pair {background-color:#677}"
echo "td.impair {background-color:#533}"
echo "td {text-align: center} </style>"
while [ $i -lt 10 ]
do
    if [ $((i % 2)) -eq 0 ]; then
        echo "<tr><td class=\"pair\">$i</td>"
        echo "<td class=\"pair\">$((i*2))</td></tr>"
    else
        echo "<tr><td class=\"impair\">$i</td>"
        echo "<td class=\"impair\">$((i*2))</td></tr>"
    fi
i=$((i+1))
done
echo "</tbody>"
echo "</table>"
echo "</html>"