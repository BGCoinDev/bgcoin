# Copyright (c) 2023-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

include(GenerateHeaders)
generate_header_from_raw(data/block413567.raw benchmark::data)

add_executable(bench_bgcoin
  bench_bgcoin.cpp
  bench.cpp
  nanobench.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/data/block413567.raw.h
# Benchmarks:
  addrman.cpp
  base58.cpp
  bech32.cpp
  bip324_ecdh.cpp
  block_assemble.cpp
  ccoins_caching.cpp
  chacha20.cpp
  checkblock.cpp
  checkblockindex.cpp
  checkqueue.cpp
  cluster_linearize.cpp
  crypto_hash.cpp
  descriptors.cpp
  disconnected_transactions.cpp
  duplicate_inputs.cpp
  ellswift.cpp
  examples.cpp
  gcs_filter.cpp
  hashpadding.cpp
  index_blockfilter.cpp
  load_external.cpp
  lockedpool.cpp
  logging.cpp
  mempool_eviction.cpp
  mempool_stress.cpp
  merkle_root.cpp
  parse_hex.cpp
  peer_eviction.cpp
  poly1305.cpp
  pool.cpp
  prevector.cpp
  random.cpp
  readblock.cpp
  rollingbloom.cpp
  rpc_blockchain.cpp
  rpc_mempool.cpp
  sign_transaction.cpp
  streams_findbyte.cpp
  strencodings.cpp
  util_time.cpp
  verify_script.cpp
  xor.cpp
)

target_link_libraries(bench_bgcoin
  core_interface
  test_util
  bgcoin_node
  Boost::headers
)

if(ENABLE_WALLET)
  target_sources(bench_bgcoin
    PRIVATE
      coin_selection.cpp
      wallet_balance.cpp
      wallet_create.cpp
      wallet_create_tx.cpp
      wallet_loading.cpp
      wallet_ismine.cpp
  )
  target_link_libraries(bench_bgcoin bgcoin_wallet)
endif()

add_test(NAME bench_sanity_check_high_priority
  COMMAND bench_bgcoin -sanity-check -priority-level=high
)

install(TARGETS bench_bgcoin
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
