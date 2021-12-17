/** \file   Ouvrage.h
 * \brief Ce fichier comprend toute les declarations comprise dans la classe Ouvrage
 * \Author M4ST3R-Y0DA-44
 *
 * \date Created on 18 novembre 2021, 14:51
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include <string>
#include "Reference.h"


/**\namespace biblio
 * \brief Un namespace qui contient la classe Reference, Ouvrage, Journal et Bibliographie ainsi que toute leur attributs et methodes*/
namespace biblio
{

  /** \class Ouvrage
   * \brief Class qui soccupe des Reference de type ouvrage. La classe est derive de la classe Reference */

  class Ouvrage : public Reference
  {
  public:
    /** \fn Ouvrage (const std::string& p_editeur, const std::string& p_ville, const std::string& p_auteur, const std::string& p_titre, const int p_annee, const std::string& p_identifiant)
     * \brief constructeur de la classe Ouvrage
     * \param p_editeur (string) nom de l'editeur de l'ouvrage
     * \param p_ville (string) nom de la ville de publication de l'ouvrage
     * \param p_auteur (string) le nom de l'auteur de la publication
     * \param p_titre (string) le titre de la publication
     * \param p_annee (int) l'annee de la publication
     * \param p_identifiant (string) le code ISBN de la publication*/
    Ouvrage (const std::string& p_editeur, const std::string& p_ville, const std::string& p_auteur, const std::string& p_titre, const int p_annee, const std::string& p_identifiant);

    /** \fn const std::string reqEditeur () const
     * \brief methode de lecture de l'attribut m_editeur
     * \return (string) nom de l'editeur de l'ouvrage*/
    const std::string reqEditeur ()const;

    /** \fn const std::string reqVille () const
     * \brief methode de lecture de l'attribut m_ville
     * \return (string) nom de la ville de publication de l'ouvrage*/
    const std::string reqVille ()const;

    /** \fn const std::string reqReferenceFormate () const
     * \brief methode d'obtention de la reference complete de l'ouvrage
     * \return (string) retourne la reference complete de l'ouvrage dans un format formate*/
    const std::string reqReferenceFormate () const;

    /** \fn virtual Reference* clone () const
     * \brief fonction qui permet de faire une copie allouee sur le monceau de l'objet courant*/
    virtual Reference* clone () const;

  private:
    /** \fn void verifieInvariant () const
     * \brief fonction qui verifie les invariants de la classe Ouvrage*/
    void verifieInvariant ()const;
    std::string m_editeur; /*\brief (string) nom de la maison d'edition de l'ouvrage*/
    std::string m_ville; /*\brief (string) nom de la ville de publication de l'ouvrage*/

  };
}
#endif /* OUVRAGE_H */

