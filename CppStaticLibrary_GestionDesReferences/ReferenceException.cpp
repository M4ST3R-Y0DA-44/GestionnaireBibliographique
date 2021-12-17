/**
 * \file  ReferenceException.cpp
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient les definitions pour la Classe ReferenceException, ReferenceDejaPresenteException et ReferenceAbsenteException.
 *
 * \date Created on 7 décembre 2021, 04:04
 */

#include "ReferenceException.h"


/*Constructeur de la classe ReferenceException*/
ReferenceException::ReferenceException (const std::string& p_raison) : std::runtime_error (p_raison) { }


/*Constructeur de la classe ReferenceDejaPresenteException*/
ReferenceDejaPresenteException::ReferenceDejaPresenteException (const std::string& p_raison) : ReferenceException (p_raison) { }


/*Constructeur de la classe ReferenceAbsenteException*/
ReferenceAbsenteException::ReferenceAbsenteException (const std::string& p_raison) : ReferenceException (p_raison) { }