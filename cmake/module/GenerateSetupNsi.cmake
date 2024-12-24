# Copyright (c) 2023-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

function(generate_setup_nsi)
  set(abs_top_srcdir ${PROJECT_SOURCE_DIR})
  set(abs_top_builddir ${PROJECT_BINARY_DIR})
  set(PACKAGE_URL ${PROJECT_HOMEPAGE_URL})
  set(PACKAGE_TARNAME "bgcoin")
  set(BITCOIN_GUI_NAME "bgcoin-qt")
  set(BITCOIN_DAEMON_NAME "bgcoind")
  set(BITCOIN_CLI_NAME "bgcoin-cli")
  set(BITCOIN_TX_NAME "bgcoin-tx")
  set(BITCOIN_WALLET_TOOL_NAME "bgcoin-wallet")
  set(BITCOIN_TEST_NAME "test_bgcoin")
  set(EXEEXT ${CMAKE_EXECUTABLE_SUFFIX})
  configure_file(${PROJECT_SOURCE_DIR}/share/setup.nsi.in ${PROJECT_BINARY_DIR}/bgcoin-win64-setup.nsi USE_SOURCE_PERMISSIONS @ONLY)
endfunction()
