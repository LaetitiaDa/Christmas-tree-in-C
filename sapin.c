#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BRWN "\e[38;5;130m"
#define NRML "\x1B[0m"
#define GREEN "\x1B[32m"

void my_putstr(char *str)
{
  while(*str != '\0')
    {
      write(1, str, 1);
      *str++;
    }
}


void my_sapin(int value)
{
  int size_c = 7;
  int size_l = 4;
  int c = 0; //index colonne
  int l = 0; //index ligne
  int num_line = 0;
  int i = 0; //index
  
  //definition de la taille des colonnes
  
  int num_col = size_c;//nombre de col de depart de chaque triangle
  int count_col = 7;
  
  for( i = 0; i < value; i++)
    {
      num_col = count_col - (2 * ((i+1) / 2));
      count_col = num_col;
      
      for( l = 0; l < (4 + i); l++)
	{
	  count_col = count_col + 2;
	}
    }
  
  //printf("nombre de colonnes totales est %d\n", num_col);
  
  l = 0;
  c = 0;
  
  int index = 1; // boucle pour créer chaque triangle
  int i_line = 0; //ajoute 1 ligne a chaque nouveau triangle
  
  int k = num_col / 2; // utiliser pour les espaces apres les etoiles
  int j = num_col / 2; // utiliser pour les espaces avant les *
  
  //créer les triangles
  
  for(index = 1; index <= value; index++)
    {
      for(l = 0; l < (size_l + i_line); l++)
	{
	  j--;
	  k++;
	  for(c = 0; c < num_col; c++)
	    {
	      if( c <= j || c >= k)
		{
		  write(1, " ", 1);
		}
	      if( c > j && c < k)
		{
		  my_putstr(GREEN); //color green
		  write(1, "*", 1);
		  my_putstr(NRML); //color normal
		}
	    }
	  write(1, "\n", 1);
	}
      k = k - 1 - ((index + 1) / 2);
      j = j + 1 + ((index + 1) / 2);
      i_line++;
    }
  

// créer le tronc

  
  j = (num_col / 2) - (value / 2);
  k = (num_col / 2) + (value / 2);
  
  for(l = 0; l < value; l++)
    {
      for(c = 0; c < num_col; c++)
	{
	  if( c < j || c > k)
	    {
	      write(1, " ", 1);
	    }
	  if( c >= j && c <= k)
	    {
	      my_putstr(BRWN); //brown
	      write(1, "|", 1);
	      my_putstr(NRML);//normal color
	    }
	}
      write(1, "\n", 1);
    }
}


int main(int argc, char *argv[])
{
      if (argc == 2)
	{
	    int value = atoi(argv[1]);
      //int value = 8;
	    system("clear"); //clear l'écran pour faire joli
	    my_sapin(value);
	}
      else
	{
	  printf("ERROR nombre d'arguments\n");
	}
    
  return (0);
}
