#!/bin/bash
rm -f a.out min_color_by_node
g++ color_by_node.cpp
for file in gc*
do
    cp $file input
    echo "$file :" >> min_color_by_node
    ./a.out >> min_color_by_node
    echo "" >> min_color_by_node
done
