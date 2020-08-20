/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_CLOSINGD_CLOSINGD_WIREGEN_H
#define LIGHTNING_CLOSINGD_CLOSINGD_WIREGEN_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>
#include <bitcoin/tx.h>
#include <common/cryptomsg.h>
#include <common/htlc_wire.h>
#include <common/per_peer_state.h>

enum closingd_wire {
        /*  Begin!  (passes peer fd */
        WIRE_CLOSINGD_INIT = 2001,
        /*  We received an offer */
        WIRE_CLOSINGD_RECEIVED_SIGNATURE = 2002,
        WIRE_CLOSINGD_RECEIVED_SIGNATURE_REPLY = 2102,
        /*  Negotiations complete */
        WIRE_CLOSINGD_COMPLETE = 2004,
};

const char *closingd_wire_name(int e);

/**
 * Determine whether a given message type is defined as a message.
 *
 * Returns true if the message type is part of the message definitions we have
 * generated parsers for, false if it is a custom message that cannot be
 * handled internally.
 */
bool closingd_wire_is_defined(u16 type);


/* WIRE: CLOSINGD_INIT */
/*  Begin!  (passes peer fd */
u8 *towire_closingd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct per_peer_state *pps, const struct bitcoin_txid *funding_txid, u16 funding_txout, struct amount_sat funding_satoshi, const struct pubkey *local_fundingkey, const struct pubkey *remote_fundingkey, enum side opener, struct amount_sat local_sat, struct amount_sat remote_sat, struct amount_sat our_dust_limit, struct amount_sat min_fee_satoshi, struct amount_sat fee_limit_satoshi, struct amount_sat initial_fee_satoshi, const u8 *local_scriptpubkey, const u8 *remote_scriptpubkey, u64 fee_negotiation_step, u8 fee_negotiation_step_unit, bool reconnected, u64 next_index_local, u64 next_index_remote, u64 revocations_received, const u8 *channel_reestablish, const struct secret *last_remote_secret, bool dev_fast_gossip);
bool fromwire_closingd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct per_peer_state **pps, struct bitcoin_txid *funding_txid, u16 *funding_txout, struct amount_sat *funding_satoshi, struct pubkey *local_fundingkey, struct pubkey *remote_fundingkey, enum side *opener, struct amount_sat *local_sat, struct amount_sat *remote_sat, struct amount_sat *our_dust_limit, struct amount_sat *min_fee_satoshi, struct amount_sat *fee_limit_satoshi, struct amount_sat *initial_fee_satoshi, u8 **local_scriptpubkey, u8 **remote_scriptpubkey, u64 *fee_negotiation_step, u8 *fee_negotiation_step_unit, bool *reconnected, u64 *next_index_local, u64 *next_index_remote, u64 *revocations_received, u8 **channel_reestablish, struct secret *last_remote_secret, bool *dev_fast_gossip);

/* WIRE: CLOSINGD_RECEIVED_SIGNATURE */
/*  We received an offer */
u8 *towire_closingd_received_signature(const tal_t *ctx, const struct bitcoin_signature *signature, const struct bitcoin_tx *tx);
bool fromwire_closingd_received_signature(const tal_t *ctx, const void *p, struct bitcoin_signature *signature, struct bitcoin_tx **tx);

/* WIRE: CLOSINGD_RECEIVED_SIGNATURE_REPLY */
u8 *towire_closingd_received_signature_reply(const tal_t *ctx, const struct bitcoin_txid *closing_txid);
bool fromwire_closingd_received_signature_reply(const void *p, struct bitcoin_txid *closing_txid);

/* WIRE: CLOSINGD_COMPLETE */
/*  Negotiations complete */
u8 *towire_closingd_complete(const tal_t *ctx);
bool fromwire_closingd_complete(const void *p);


#endif /* LIGHTNING_CLOSINGD_CLOSINGD_WIREGEN_H */

// SHA256STAMP:exp-0-3235ada6c1c749bfb3885b20dae4c3a7deaa1b2716e34f30405a66cbe32d1055