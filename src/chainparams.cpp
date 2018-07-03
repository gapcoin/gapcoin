// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "main.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"
#include "PoWCore/src/PoW.h"
#include "PoWCore/src/PoWProcessor.h"
#include "PoWCore/src/PoWUtils.h"
#include "PoWCore/src/Sieve.h"

#include <boost/assign/list_of.hpp>

#define GENESIS_NONCE 13370
#define GENESIS_ADDER { 233, 156, 15 }
#define GENESIS_SHIFT 20
#define GENESIS_TN_NONCE 1
#define GENESIS_TN_ADDER { 25, 1 }

using namespace boost::assign;

//
// Main network
//
/* ip seeds */
unsigned int pnSeed[] =
{
  0x9b8fe3d4, 0x52458368, 0x092cd75f, 0xb324fe9b, 0xc0e27fc7,
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment. 0xd1dfe6f9
        pchMessageStart[0] = 0xd1;
        pchMessageStart[1] = 0xdf;
        pchMessageStart[2] = 0xe6;
        pchMessageStart[3] = 0xf9;
        vAlertPubKey = ParseHex("04a6395c1468b52d9fd79a1092f0fe223ae8e0704bd440630ccac26b05c8d4f7f7836c4d811f915ad8000c1c171619850608e03b93ddfe4a324494c9c5b68f0993"); 
        nDefaultPort = 31469;
        nRPCPort = 31397;
        nSubsidyHalvingInterval = 420000;

        const char* pszTimestamp = "The Times 15/Oct/2014 US data sends global stocks into tail-spin";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("044588d54931b7de2f9faaa5a3c1fde654114ae51273754e1f3f9720127f8977af6bfaa1f33e22e80e4b83f5269921501b411d254929faf1b10d2174ded28ac59d") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion    = 1;
        genesis.nTime       = GENESIS_TIME;
        genesis.nDifficulty = PoWUtils::min_difficulty;
        genesis.nNonce      = GENESIS_NONCE;
        genesis.nShift      = GENESIS_SHIFT;
        uint8_t nAdd[]      = GENESIS_ADDER;
        genesis.nAdd.assign(nAdd, nAdd + sizeof(nAdd) / sizeof(uint8_t));

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256(GENESIS_HASH));
        assert(genesis.hashMerkleRoot == uint256(GENESIS_MERKLE));

        base58Prefixes[PUBKEY_ADDRESS] = {38};
        base58Prefixes[SCRIPT_ADDRESS] = {5};
        base58Prefixes[SECRET_KEY] = {97};
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xb2, 0x1e};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xad, 0xe4};

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x0b;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0x09;
        pchMessageStart[3] = 0x07;
        vAlertPubKey = ParseHex("04f122609fbdbf62e4cb5392845b7a60d22b74d075e5bb1bcc296814f720e41ad44486b57aa9c4cb758d6ac6f0c703407dcc64ed000bb7367d8c6c5bbe8b582f0f");
        nDefaultPort = 19661;
        nRPCPort = 19609;
        strDataDir = "testnet3";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime       = GENESIS_TIME;
        genesis.nDifficulty = PoWUtils::min_test_difficulty;
        genesis.nNonce      = GENESIS_TN_NONCE;
        uint8_t nAdd[]      = GENESIS_TN_ADDER;
        genesis.nAdd.assign(nAdd, nAdd + sizeof(nAdd) / sizeof(uint8_t));

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256(GENESIS_TN_HASH));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = {111};
        base58Prefixes[SCRIPT_ADDRESS] = {196};
        base58Prefixes[SECRET_KEY] = {239};
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xcf};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test 
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nSubsidyHalvingInterval = 1200;

        genesis.nTime       = GENESIS_TIME;
        genesis.nDifficulty = PoWUtils::min_difficulty;
        genesis.nNonce      = GENESIS_NONCE;
        genesis.nShift      = GENESIS_SHIFT;
        uint8_t nAdd[]      = GENESIS_ADDER;
        genesis.nAdd.assign(nAdd, nAdd + sizeof(nAdd) / sizeof(uint8_t));

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";

        assert(hashGenesisBlock == uint256(GENESIS_HASH));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
