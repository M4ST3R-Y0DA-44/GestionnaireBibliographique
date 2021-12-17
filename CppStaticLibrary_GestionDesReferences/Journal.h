/** \file   Journal.h
 * \brief Ce fichier contient toute les declarations comprise dans la Classe Journal
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 18 novembre 2021, 15:00
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include "Reference.h"

/**\namespace biblio
 * \brief Un namespace qui contient la classe Reference, Ouvrage, Journal et Bibliographie ainsi que toute leur attributs et methodes*/
namespace biblio
{

  /** \class Journal
   * \brief Classe qui creer et manipule les objet de type Journal. Cette classe derive de la classe Reference. */

  class Journal : public Reference
  {
  public:
    /** \fn Journal (const std::string& p_nom, const int p_volume, const int p_numero, const int p_page, const std::string& p_auteur, const std::string& p_titre, const int p_annee, const std::string& p_identifiant)
     * \brief Constructeur de la classe Journal.
     * \param p_nom (string) le nom du journal de publication
     * \param p_volume (int) le volume de la publication
     * \param p_numero (int) Le numero de la publication
     * \param p_page (int) la page de publication
     * \param p_auteur (string) nom de l'auteur
     * \param p_titre (string) le titre de la publication
     * \param p_annee (int) l'annee de publication
     * \param p_identifiant (string) represente un string du code ISSN de la Reference*/
    Journal (const std::string& p_nom, const int p_volume, const int p_numero, const int p_page, const std::string& p_auteur, const std::string& p_titre, const int p_annee, const std::string& p_identifiant);

    /** \fn const std::string reqNom() const
     * \brief methode de lecture de l'attribut m_nom
     * \return (string) contenant une copie de l'attribut m_nom*/
    const std::string reqNom () const;

    /** \fn const int reqVolume() const
     * \brief methode de lecture de l'attribut m_volume
     * \return (int) le numero de volume du Journal*/
    const int reqVolume () const;

    /** \fn const int reqNumero() const
     * \brief methode de lecture de l'attribut m_numero
     * \return (int) le numero de la publication*/
    const int reqNumero () const;

    /** \fn const int reqPage() const
     * \brief methode de lecture de l'attribut m_page
     * \return (int) le numero de page de debut de la publication dans le Journal*/
    const int reqPage () const;

    /** \fn const std::string reqReferenceFormate() const
     * \brief methode pour obtenir un string formate de la Reference complete du Journal
     * \return (string) retourne la Reference du Journal dans un format formate*/
    const std::string reqReferenceFormate () const;

    /** \fn virtual Reference* clone() const
     * \brief fonction qui permet de faire une copie allouee sur le monceau de l'objet courant*/
    virtual Reference* clone () const;

  private:
    /** \fn void verifieInvariant() const
     * \brief fonction qui verifie les invariants de la classe Journal*/
    void verifieInvariant () const;
    std::string m_nom; /*\brief (string) nom du journal de publication*/
    int m_volume; /*\brief (int) volume du journal*/
    int m_numero; /*\brief (int) numero du Journal*/
    int m_page; /*\brief (int) numero de debut de l'article dans le journal*/

  };
}

#endif /* JOURNAL_H */

