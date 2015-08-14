#!/bin/bash

`clear`

echo "\n1---------------------------------\n"

param='0 1 2 3' 
echo "PARAM : $param \n\nRET : "
./push_swap $param

echo "\n2---------------------------------\n"

param='2 1 0 3' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n3---------------------------------\n"

param='0 3 1 2' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n4---------------------------------\n"

param='3 0 1 2' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n5---------------------------------\n"

param='2 3 1 0'
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n6---------------------------------\n"

param='1 2 3 0' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n7---------------------------------\n"

param='0 1 3 2' 
echo "\nPARAM : $param \n\nRET : "
./push_swap $param
echo "\n8---------------------------------\n"

param='0 2 1 3' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n9---------------------------------\n"

param='2 1 3 0' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n10---------------------------------\n"

param='3 2 1 0' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n11---------------------------------\n"

param='0 3 2 1' 
echo "PARAM : $param \n\nRET : "
./push_swap $param
echo "\n12---------------------------------\n"

param='2 3 0 1' 
echo "PARAM : $param \n\nRET : "
./push_swap $param

echo "\n---------------------------------\n"

