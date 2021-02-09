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
echo "<style type=\"text/css\">"
echo "td {text-align: center} </style>"
echo "<tr><td colspan=\"2\"> 0 </td>"
i=1
while [ $i -lt 10 ]
do
echo "<tr><td>$i</td>"
echo "<td>$((i*2))</td></tr>"
i=$((i+1))
done
echo "</tbody>"
echo "</table>"
echo "</html>"