#include "categories_units.h"

Categories_units::Categories_units()
{
}


QDataStream & operator<< (QDataStream& stream, const Categories_units& m_categorie)
{
    stream<<m_categorie.m_category;
    stream<<m_categorie.m_units;

    return stream;
}


QDataStream & operator>> (QDataStream& stream, Categories_units& m_categorie)
{
    stream>>m_categorie.m_category;
    stream>>m_categorie.m_units;

    return stream;
}
