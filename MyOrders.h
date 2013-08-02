/*
    This file is part of the Zero Reserve Plugin for Retroshare.

    Zero Reserve is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Zero Reserve is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Zero Reserve.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef MYORDERS_H
#define MYORDERS_H

#include "OrderBook.h"


/**
 * @brief Holds pointers to all orders from myself
 */

class MyOrders : public OrderBook
{
    Q_OBJECT
    MyOrders();

public:
    MyOrders(OrderBook *bids, OrderBook *asks);
    virtual int columnCount(const QModelIndex&) const;
    virtual QVariant data(const QModelIndex&, int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    /** Matches our new orders with all others */
    void match(Order *order);
    virtual bool addOrder( Order * order );


private:
    OrderBook * m_bids;
    OrderBook * m_asks;
};

#endif // MYORDERS_H
