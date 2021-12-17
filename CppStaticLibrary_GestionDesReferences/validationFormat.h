/**
 * \file   validationFormat.h
 * \brief Ce fichier declare un namespace util qui contient 3 fonction de validation que nous avons creer dans le cadre du TP1. Elle contient une fonction de validation de nom d'auteur, de validation de code ISSN et de validation du code ISBN.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 29 septembre 2021, 19:04
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

/**\namespace util
 * \brief Ce namespace contient trois fonction de validation, soit une validation du nom d'auteur, un validation du ISSN et une validation du ISBN.*/
namespace util
{
  /** \fn bool validerFormatNom (const std::string& p_nom)
   * \brief methode qui permet de verifier si le nom d'auteur est dans le bon format
   * \param p_nom (string) prenom et nom de l'auteur de la publication
   * \return retourne vrai si le nom est dans le bon format, faux sinon*/
  bool validerFormatNom (const std::string& p_nom);

  /** \fn bool validerCodeIssn (const std::string& p_issn)
   * \brief methode qui permet de verifier si le code ISSN est dans le bon format et est valide
   * \param p_issn (string) code ISSN (incluant le prefixe ISSN)
   * \return retourne vrai si le code est valide et dans le bon format, faux sinon*/
  bool validerCodeIssn (const std::string& p_issn);

  /** \fn bool validerCodeIsbn (const std::string& p_isbn)
   * \brief methode qui permet de verifier si le code ISBN est dans le bon format et est valide
   * \param p_isbn (string) code ISBN (incluant le prefixe ISBN)
   * \return retourne vrai si le code ISBN est valide et dans le bon format, faux sinon*/
  bool validerCodeIsbn (const std::string& p_isbn);
}

#endif /* VALIDATIONFORMAT_H */

