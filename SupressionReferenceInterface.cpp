/**
 * \file   SupressionReferenceInterface.cpp
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient les definitions de la classe SupressionReferenceInterface.
 *
 * \date Created on 7 décembre 2021, 16:40
 */

#include "SupressionReferenceInterface.h"
#include "validationFormat.h"
#include <QMessageBox>


/*Constructeur de la classe*/
SupressionReferenceInterface::SupressionReferenceInterface ()
{
  widget.setupUi (this);
}


/*Destructeur de la classe*/
SupressionReferenceInterface::~SupressionReferenceInterface () { }


/*Methode de lecture du code identifiant*/
QString
SupressionReferenceInterface::reqCodeId () const
{
  return widget.txtISBN->text ();
}


void
SupressionReferenceInterface::validerCode ()
{
  if (! (util::validerCodeIsbn (reqCodeId ().toStdString ()) || (util::validerCodeIssn (reqCodeId ().toStdString ()))))
    {
      QString message ("le code que vous avez entre est invalide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
}
