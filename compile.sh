echo "compilando proyecto"
gcc -Wall test.c */*.c */*.h -o run
#gcc -c -Wall *.c -g */*.c -g */*.h -o run
echo "corriendo proyecto"
./run
rm run
echo "Saliendo, bay"
 
