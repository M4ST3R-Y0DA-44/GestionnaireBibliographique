/**
 * \file  validationFormat.cpp
 * \brief Ce fichier contient un namespace util qui contient toutes les definitions des fonctions de validation que nous avons creer au TP1, soit la fonction de validation des nom, et la fonction de validation des code ISSN et ISBN.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 18 octobre 2021, 14:30
 */
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include "validationFormat.h"

using namespace std;

namespace util
{


  bool
  validerFormatNom (const string& p_nom)
  {
    bool nomValide = true;
    if (p_nom.size () == 0)
      {
        nomValide = false;
      }
    else
      {
        int i = 0;
        char strNom[p_nom.size () + 1];
        strcpy (strNom, p_nom.c_str ());
        while (i < p_nom.size ())
          {
            if (isalpha (strNom[i]))
              {
                i++;
              }
            else
              {
                if (isdigit (strNom[i]))
                  {
                    nomValide = false;
                  }
                else
                  {
                    if (p_nom.size () - i > 1)
                      {
                        int peekNextLetter = i + 1;
                        if (isalpha (strNom[peekNextLetter]) == false)
                          {
                            nomValide = false;
                          }
                      }
                  }
                i++;
              }
          }
      }
    return nomValide;
  }


  bool
  validerCodeIssn (const std::string & p_issn)
  {
    bool formatIssnValide = true;
    bool issnValide = false;
    char strIssn[p_issn.size () + 1];
    strcpy (strIssn, p_issn.c_str ());

    if (p_issn.size () == 14)
      {
        if (p_issn.substr (0, 1).compare ("I") != 0)
          {
            formatIssnValide = false;
          }
        if (p_issn.substr (1, 1).compare ("S") != 0)
          {
            formatIssnValide = false;
          }
        if (p_issn.substr (2, 1).compare ("S") != 0)
          {
            formatIssnValide = false;
          }
        if (p_issn.substr (3, 1).compare ("N") != 0)
          {
            formatIssnValide = false;
          }
        if (p_issn.substr (4, 1).compare (" ") != 0)
          {
            formatIssnValide = false;
          }
        for (int j = 5; j < 9; j++)
          {
            if (isdigit (strIssn[j]) == false)
              {
                formatIssnValide = false;
              }
          }
        if (p_issn.substr (9, 1).compare ("-") != 0)
          {
            formatIssnValide = false;
          }
        for (int j = 10; j < 14; j++)
          {
            if (isdigit (strIssn[j]) == false)
              {
                formatIssnValide = false;
              }
          }
      }
    else
      {
        formatIssnValide = false;
      }

    if (formatIssnValide)
      {
        int issn1 = atoi ((p_issn.substr (5, 1)).c_str ());
        int issn2 = atoi ((p_issn.substr (6, 1)).c_str ());
        int issn3 = atoi ((p_issn.substr (7, 1)).c_str ());
        int issn4 = atoi ((p_issn.substr (8, 1)).c_str ());
        int issn5 = atoi ((p_issn.substr (10, 1)).c_str ());
        int issn6 = atoi ((p_issn.substr (11, 1)).c_str ());
        int issn7 = atoi ((p_issn.substr (12, 1)).c_str ());
        string issn8 = (p_issn.substr (13, 1)).c_str ();
        int somme = 0;
        int restDivision = 0;
        int dernierIssn = 0;
        string dernierIssnConvertie;

        somme = (issn1 * 8) + (issn2 * 7) + (issn3 * 6) + (issn4 * 5) + (issn5 * 4) + (issn6 * 3) + (issn7 * 2);
        restDivision = somme % 11;
        dernierIssn = 11 - restDivision;

        if (p_issn.substr (13, 1) == "X" && dernierIssn == 10)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "0" && dernierIssn == 0)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "1" && dernierIssn == 1)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "2" && dernierIssn == 2)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "3" && dernierIssn == 3)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "4" && dernierIssn == 4)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "5" && dernierIssn == 5)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "6" && dernierIssn == 6)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "7" && dernierIssn == 7)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "8" && dernierIssn == 8)
          {
            issnValide = true;
          }
        if (p_issn.substr (13, 1) == "9" && dernierIssn == 9)
          {
            issnValide = true;
          }
      }
    return issnValide;
  }


  bool
  validerCodeIsbn (const std::string & p_isbn)
  {
    bool formatIsbnValide = true;
    char isbnComplet[p_isbn.size () + 1];
    strcpy (isbnComplet, p_isbn.c_str ());
    string isbnOnlyNumber;

    if (p_isbn.size () == 22)
      {
        if (p_isbn.substr (0, 1).compare ("I") != 0)
          {
            formatIsbnValide = false;
          }
        if (p_isbn.substr (1, 1).compare ("S") != 0)
          {
            formatIsbnValide = false;
          }
        if (p_isbn.substr (2, 1).compare ("B") != 0)
          {
            formatIsbnValide = false;
          }
        if (p_isbn.substr (3, 1).compare ("N") != 0)
          {
            formatIsbnValide = false;
          }

        if (p_isbn.substr (4, 1).compare (" ") != 0)
          {
            if (p_isbn.substr (4, 1).compare ("-") != 0)
              {
                formatIsbnValide = false;
              }
          }

        if (p_isbn.substr (5, 3).compare ("978") != 0)
          {
            if (p_isbn.substr (5, 3).compare ("979") != 0)
              {
                formatIsbnValide = false;
              }
          }
        isbnOnlyNumber.append (p_isbn.substr (5, 3));

        if (p_isbn.substr (8, 1).compare ("-") != 0)
          {
            formatIsbnValide = false;
          }

        int i = 9;
        while (isdigit (isbnComplet[i]))
          {
            i++;
          }

        int lenght = i - 9;
        int domaine = atoi ((p_isbn.substr (9, lenght)).c_str ());
        isbnOnlyNumber.append (p_isbn.substr (9, lenght));

        if (domaine < 0 || domaine == 6 || domaine > 99999)
          {
            formatIsbnValide = false;
          }
        if (domaine >= 7 && domaine <= 80)
          {
            formatIsbnValide = false;
          }
        if (domaine >= 95 && domaine <= 600)
          {
            formatIsbnValide = false;
          }
        if (domaine >= 649 && domaine <= 950)
          {
            formatIsbnValide = false;
          }
        if (domaine >= 989 && domaine <= 9900)
          {
            formatIsbnValide = false;
          }
        if (domaine >= 9989 && domaine <= 99900)
          {
            formatIsbnValide = false;
          }

        if (p_isbn.substr (i, 1).compare ("-") != 0)
          {
            formatIsbnValide = false;
          }

        i += 1;

        if (isdigit (isbnComplet[i]) == false)
          {
            formatIsbnValide = false;
          }

        int saveValue = i;
        while (isdigit (isbnComplet[i]))
          {
            i++;
          }
        lenght = i - saveValue;
        int editeur = atoi ((p_isbn.substr (saveValue, lenght)).c_str ());
        isbnOnlyNumber.append (p_isbn.substr (saveValue, lenght));

        if (editeur < 0 || editeur > 9999999)
          {
            formatIsbnValide = false;
          }
        if (editeur >= 19 && editeur <= 200)
          {
            formatIsbnValide = false;
          }
        if (editeur >= 699 && editeur <= 7000)
          {
            formatIsbnValide = false;
          }
        if (editeur >= 8499 && editeur <= 85000)
          {
            formatIsbnValide = false;
          }
        if (editeur >= 89999 && editeur <= 900000)
          {
            formatIsbnValide = false;
          }
        if (editeur >= 949999 && editeur <= 9500000)
          {
            formatIsbnValide = false;
          }

        if (p_isbn.substr (i, 1).compare ("-") != 0)
          {
            formatIsbnValide = false;
          }

        i += 1;

        if (isdigit (isbnComplet[i]) == false)
          {
            formatIsbnValide = false;
          }

        saveValue = i;
        while (isdigit (isbnComplet[i]))
          {
            i++;
          }

        lenght = i - saveValue;
        int numTitre = atoi ((p_isbn.substr (saveValue, lenght)).c_str ());
        isbnOnlyNumber.append (p_isbn.substr (saveValue, lenght));

        if (p_isbn.substr (i, 1).compare ("-") != 0)
          {
            formatIsbnValide = false;
          }

        i += 1;

        if (isdigit (isbnComplet[i]) == false)
          {
            formatIsbnValide = false;
          }


        if (formatIsbnValide)
          {
            int lastDigit = atoi ((p_isbn.substr (i, 1)).c_str ());
            isbnOnlyNumber.append (p_isbn.substr (i, 1));

            int total = 0;

            for (i = 0; i < 12; i += 2)
              {
                total += atoi ((isbnOnlyNumber.substr (i, 1)).c_str ());
              }
            for (i = 1; i < 13; i += 2)
              {
                total += (3 * atoi ((isbnOnlyNumber.substr (i, 1)).c_str ()));
              }
            int calculLastDigit;
            calculLastDigit = 10 - (total % 10);

            if (lastDigit != calculLastDigit)
              {
                formatIsbnValide = false;
              }

          }
      }
    else
      {
        formatIsbnValide = false;
      }

    return formatIsbnValide;
  }
}



