/**
 * \file   AjoutOuvrageInterface.h
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient la classe AjoutOuvrageInterface.
 *
 * \date Created on 7 décembre 2021, 16:33
 */

#ifndef _AJOUTOUVRAGEINTERFACE_H
#define _AJOUTOUVRAGEINTERFACE_H

#include "ui_AjoutOuvrageInterface.h"

/**
 * \class AjoutOuvrageInterface
 * \brief cette classe permet de creer l'interface d'ajout de reference de type Ouvrage.*/
class AjoutOuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  /**
   * \fn AjoutOuvrageInterface ()
   * \brief Constructeur de la classe AjoutOuvrageInterface*/
  AjoutOuvrageInterface ();

  /**
   * \fn virtual ~AjoutOuvrageInterface ()
   * \brief Destructeur de la classe AjoutOuvrageInterface*/
  virtual ~AjoutOuvrageInterface ();

  /**
   * \fn QString reqNomAuteur () const
   * \brief methode de lecture du text dans le champs nom auteur de l'interface
   * \return (QString) contient le nom de l'auteur sous une chaine string. */
  QString reqNomAuteur () const;

  /**
   * \fn QString reqTitre () const
   * \brief methode de lecture du text dans le champ titre de l'interface
   * \return (QString) contient le titre sous une chaine string. */
  QString reqTitre () const;

  /**
   * \fn int reqAnnee () const
   * \brief methode de lecture de la valeur dans le champ annee de l'interface.
   * \return (int) annee de publication du champs de l'interface*/
  int reqAnnee () const;

  /**
   * \fn QString reqNomEditeur () const
   * \brief methode de lecture du nom de l'editeur dans le champs nom editeur de l'interface.
   * \return (QString) nom de l'editeur contenue par le champs de l'interface.*/
  QString reqNomEditeur () const;

  /**
   * \fn reqVille () const
   * \brief methode qui fait la du nom de la ville d'edition dans le champs ville de l'interface.
   * \return (QString) nom de la ville contenue dans le champs de l'interface. */
  QString reqVille () const;

  /**
   * \fn QString reqCodeIsbn () const
   * \brief methode de lecture du code ISBN contenue dans le champs code isbn de l'application.
   * \return (QString) code ISBN contenue dans le champs code de l'application. */
  QString reqCodeIsbn () const;

private slots:
  /**
   * \fn void validerOuvrage ()
   * \brief methode (slot) de la page AjoutOuvrageInterface qui permet de valider les donnee de l'ouvrage*/
  void validerOuvrage ();

private:
  Ui::AjoutOuvrageInterface widget; /**<\brief ui de AjoutOuvrageInterface*/
};

#endif /* _AJOUTOUVRAGEINTERFACE_H */
