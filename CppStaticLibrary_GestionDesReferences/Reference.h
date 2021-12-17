/** \file   Reference.h
 * \brief Ce fichier contient la declaration de la class Reference a l'interieur du namespace biblio. La classe reference permet la creation d'une reference bibliographique et de manipuler ces differents attributs.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 18 octobre 2021, 12:32
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>

/**\namespace biblio
 * \brief Un namespace qui contient la classe Reference, Ouvrage, Journal et Bibliographie ainsi que toute leur attributs et methodes*/
namespace biblio
{

  /**
   * \class Reference
   * \brief Classe qui implante le concept de reference bibliographique */

  class Reference
  {
  public:
    /** \fn Reference (const std::string& p_auteurs, const std::string& p_titre, const int p_annee, const std::string& p_identifiant)
     * \brief Constructeur de la classe Reference
     * \param p_auteurs (string)nom de l'auteur de la reference bibliographique
     * \param p_titre (string) titre de la reference bibliographique
     * \param p_annee (int) annee de publication de la reference bibliographique
     * \param p_identifiant (string) code ISSN ou ISBN de la reference bibliographique*/
    Reference (const std::string& p_auteurs, const std::string& p_titre, const int p_annee, const std::string& p_identifiant);

    /** \fn const std::string reqAuteur () const
     * \brief methode qui retourne une lecture de l'attribut m_auteurs en string
     * \return retourne un string de l'attribut m_auteurs de l'objet Reference*/
    const std::string reqAuteur () const;

    /** \fn const std::string reqTitre () const
     * \brief methode qui retourne une lecture de l'attribut m_titre en string
     * \return retourne un string de l'attribut m_titre de l'objet Reference*/
    const std::string reqTitre () const;

    /** \fn const unsigned int reqAnnee () const
     * \brief methode qui retourne une lecture de l'attribut m_annee en unsigned int
     * \return retourne un unsigned int de l'attribut m_annee de l'objet Reference*/
    const int reqAnnee () const;

    /** \fn const std::string reqIdentifiant () const
     * \brief methode qui retourne une lecture de l'attribut m_identifiant en string
     * \return retourne un string de l'attribut m_identifiant (code ISBN/ISSN) de l'objet Reference*/
    const std::string reqIdentifiant () const;

    /** \fn virtual const std::string reqReferenceFormate () const = 0
     * \brief methode qui retourne les attributs m_auteurs, m_titre, m_annee et m_identifiant dans un string formate
     * \return retourne un string formate des attributs (m_auteurs, m_titre, m_annee, m_identifiant) de la Reference*/
    virtual const std::string reqReferenceFormate () const = 0;

    /** \fn const bool estEgal (const Reference& p_reference) const
     * \brief methode qui permet de verifier si tout les attributs entre deux References sont identique
     * \param
  p_reference (Reference) objet de comparaison
     * \return retourne vrai si les 4 attributs sont identique, faux sinon*/
    const bool estEgal (const Reference& p_reference) const;

    /** \fn virtual Reference* clone() const = 0
     * \brief methode qui clonde l'objet Reference via un pointeur*/
    virtual Reference* clone () const = 0;

    /** \fn virtual ~Reference() {}
     * \brief destructeur de la classe Reference qui declenche aussi les destructeurs des classes derives*/
    virtual
    ~Reference () { };

  protected:
    /** \fn const void asgAnnee (const int& p_annee)
     * \brief methode qui permet de modifier l'attribut m_annee d'un objet Reference
     * \param p_annee (unsigned int) nouvelle annee a inscrire*/
    const void asgAnnee (const int &p_annee);

  private:
    /** \fn void verifieInvariant () const
     * \brief methode qui verifie les invariant de la classe Reference*/
    void verifieInvariant () const;
    std::string m_auteurs; /**< \brief un string du nom de l'auteur de la Reference*/
    std::string m_titre; /**< \brief un string du titre de la reference*/
    int m_annee; /**< \brief un int de l'annee de publication de la reference*/
    std::string m_identifiant; /**< \brief un string du code ISSN ou ISBN*/
  };
}

#endif /* REFERENCE_H */

