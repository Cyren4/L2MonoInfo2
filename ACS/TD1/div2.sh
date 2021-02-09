#! /bin/bash

echo "<!DOCTYPE html>"

echo "<html>"
echo "<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />"
echo "<table>"
echo "<caption><b>Table de 2</b></caption>"

echo "<tbody>"
i=0
mult=1
while [ $i -lt 10 ]
do
if [ $i -eq 0 ]; then
    if [ $mult -eq 1 ]; then
        echo "<tr><th> x </th>"
        echo "<th> $i </th>"
     else
        echo "<tr><th> 2x </th>"
        echo "<td> $i </td>"
    fi
    i=$((i+1))
    continue
fi

if [ $mult -eq 1 ]; then
    echo "<th>$((i*mult))</th>"
else
    echo "<td>$((i*mult))</td>"
fi

i=$((i+1))

if [ $i -eq 10 ]; then
    echo "</tr>"
    if [ $mult -eq 1 ]; then
    mult=2
    i=0
    fi
fi
done
echo "</tbody>"
echo "</table>"
echo "</html>"