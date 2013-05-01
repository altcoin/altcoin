// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 The AltCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
<<<<<<< HEAD
        boost::assign::map_list_of
        (     1, uint256("0x0")) // No checkpoints before coin is started!
        ;
=======
            boost::assign::map_list_of
            (     1, uint256("0xfdbe99b90c90bae7505796461471d89ae8388ab953997aa06a355bbda8d915cb"))
            (     22267, uint256("0x23dc7d871fc2a9b994112e978019f6370bab0b8979f557afe77a7ab620224b70"))
			(     22847, uint256("0x1450b80c150fee1e657ee8309819276342c021fab5e6a20ccf5407f5e2218d0f"))
			(     23453, uint256("0x7c25d3f9671e1d9400c9a1be2ff68e68db561ab85ae6b7020062d8d26da81e4c"))
            (     28230, uint256("0xd3feb71f92c63c682f994d7c615adc425226c669a83d46012b32fc8d518b08bb"))
            ;

>>>>>>> abb747b... Fall back to IPv4 if IPv6 fails

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
	return NULL;  // No checkpoints before the coin is started!
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
