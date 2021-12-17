/*
 * \file    main.cpp
 * \author M4ST3R-Y0DA-44
 * \brief ce fichier contient le program principale de l'application Qt du TP4.
 *
 * \date Created on 6 décembre 2021, 21:33
 */

#include <QApplication>
#include "FenetrePrincipale.h"
#include "Bibliographie.h"


int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  FenetrePrincipale Fenetre ;
  Fenetre.show ();


  return app.exec ();
}
