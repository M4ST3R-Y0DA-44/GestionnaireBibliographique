/**
 * \file   SupressionReferenceInterface.h
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient les declarations de la classe SupressionReferenceInterface.
 *
 * \date Created on 7 décembre 2021, 16:40
 */

#ifndef _SUPRESSIONREFERENCEINTERFACE_H
#define _SUPRESSIONREFERENCEINTERFACE_H

#include "ui_SupressionReferenceInterface.h"

/**
 * \class SupressionReferenceInterface
 * \brief Cette classe permet la creation de la boite de dialog pour supprimer une reference de la bibliographie. */
class SupressionReferenceInterface : public QDialog
{
  Q_OBJECT
public:
  /**
   * \fn SupressionReferenceInterface ()
   * \brief Constructeur de la classe SupressionReferenceInterface*/
  SupressionReferenceInterface ();

  /**
   * \fn ~SupressionReferenceInterface ()
   * \brief Destructeur de la classe SupressionReferenceInterface*/
  virtual ~SupressionReferenceInterface ();

  /**
   * \fn QString reqCodeId () const
   * \brief methode de lecture du code ISBN/ISSN contenue dans le champs code identifiant de l'application.
   * \return (QString) code ISBN/ISSN contenue dans le champs code de l'application. */
  QString reqCodeId () const;

private slots:
  /**
   * \fn void validerCode()
   * \brief methode (Slots) de la validation du Code avant de le chercher dans le but de le supprimer*/
  void validerCode ();


private:
  Ui::SupressionReferenceInterface widget; /**<\brief ui de SupressionReferenceInterface*/
};

#endif /* _SUPRESSIONREFERENCEINTERFACE_H */
