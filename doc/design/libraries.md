# Libraries

| Name                     | Description |
|--------------------------|-------------|
| *libbgcoin_cli*         | RPC client functionality used by *bgcoin-cli* executable |
| *libbgcoin_common*      | Home for common functionality shared by different executables and libraries. Similar to *libbgcoin_util*, but higher-level (see [Dependencies](#dependencies)). |
| *libbgcoin_consensus*   | Consensus functionality used by *libbgcoin_node* and *libbgcoin_wallet*. |
| *libbgcoin_crypto*      | Hardware-optimized functions for data encryption, hashing, message authentication, and key derivation. |
| *libbgcoin_kernel*      | Consensus engine and support library used for validation by *libbgcoin_node*. |
| *libbgcoinqt*           | GUI functionality used by *bgcoin-qt* and *bgcoin-gui* executables. |
| *libbgcoin_ipc*         | IPC functionality used by *bgcoin-node*, *bgcoin-wallet*, *bgcoin-gui* executables to communicate when [`-DWITH_MULTIPROCESS=ON`](multiprocess.md) is used. |
| *libbgcoin_node*        | P2P and RPC server functionality used by *bgcoind* and *bgcoin-qt* executables. |
| *libbgcoin_util*        | Home for common functionality shared by different executables and libraries. Similar to *libbgcoin_common*, but lower-level (see [Dependencies](#dependencies)). |
| *libbgcoin_wallet*      | Wallet functionality used by *bgcoind* and *bgcoin-wallet* executables. |
| *libbgcoin_wallet_tool* | Lower-level wallet functionality used by *bgcoin-wallet* executable. |
| *libbgcoin_zmq*         | [ZeroMQ](../zmq.md) functionality used by *bgcoind* and *bgcoin-qt* executables. |

## Conventions

- Most libraries are internal libraries and have APIs which are completely unstable! There are few or no restrictions on backwards compatibility or rules about external dependencies. An exception is *libbgcoin_kernel*, which, at some future point, will have a documented external interface.

- Generally each library should have a corresponding source directory and namespace. Source code organization is a work in progress, so it is true that some namespaces are applied inconsistently, and if you look at [`add_library(bgcoin_* ...)`](../../src/CMakeLists.txt) lists you can see that many libraries pull in files from outside their source directory. But when working with libraries, it is good to follow a consistent pattern like:

  - *libbgcoin_node* code lives in `src/node/` in the `node::` namespace
  - *libbgcoin_wallet* code lives in `src/wallet/` in the `wallet::` namespace
  - *libbgcoin_ipc* code lives in `src/ipc/` in the `ipc::` namespace
  - *libbgcoin_util* code lives in `src/util/` in the `util::` namespace
  - *libbgcoin_consensus* code lives in `src/consensus/` in the `Consensus::` namespace

## Dependencies

- Libraries should minimize what other libraries they depend on, and only reference symbols following the arrows shown in the dependency graph below:

<table><tr><td>

```mermaid

%%{ init : { "flowchart" : { "curve" : "basis" }}}%%

graph TD;

bgcoin-cli[bgcoin-cli]-->libbgcoin_cli;

bgcoind[bgcoind]-->libbgcoin_node;
bgcoind[bgcoind]-->libbgcoin_wallet;

bgcoin-qt[bgcoin-qt]-->libbgcoin_node;
bgcoin-qt[bgcoin-qt]-->libbgcoinqt;
bgcoin-qt[bgcoin-qt]-->libbgcoin_wallet;

bgcoin-wallet[bgcoin-wallet]-->libbgcoin_wallet;
bgcoin-wallet[bgcoin-wallet]-->libbgcoin_wallet_tool;

libbgcoin_cli-->libbgcoin_util;
libbgcoin_cli-->libbgcoin_common;

libbgcoin_consensus-->libbgcoin_crypto;

libbgcoin_common-->libbgcoin_consensus;
libbgcoin_common-->libbgcoin_crypto;
libbgcoin_common-->libbgcoin_util;

libbgcoin_kernel-->libbgcoin_consensus;
libbgcoin_kernel-->libbgcoin_crypto;
libbgcoin_kernel-->libbgcoin_util;

libbgcoin_node-->libbgcoin_consensus;
libbgcoin_node-->libbgcoin_crypto;
libbgcoin_node-->libbgcoin_kernel;
libbgcoin_node-->libbgcoin_common;
libbgcoin_node-->libbgcoin_util;

libbgcoinqt-->libbgcoin_common;
libbgcoinqt-->libbgcoin_util;

libbgcoin_util-->libbgcoin_crypto;

libbgcoin_wallet-->libbgcoin_common;
libbgcoin_wallet-->libbgcoin_crypto;
libbgcoin_wallet-->libbgcoin_util;

libbgcoin_wallet_tool-->libbgcoin_wallet;
libbgcoin_wallet_tool-->libbgcoin_util;

classDef bold stroke-width:2px, font-weight:bold, font-size: smaller;
class bgcoin-qt,bgcoind,bgcoin-cli,bgcoin-wallet bold
```
</td></tr><tr><td>

**Dependency graph**. Arrows show linker symbol dependencies. *Crypto* lib depends on nothing. *Util* lib is depended on by everything. *Kernel* lib depends only on consensus, crypto, and util.

</td></tr></table>

- The graph shows what _linker symbols_ (functions and variables) from each library other libraries can call and reference directly, but it is not a call graph. For example, there is no arrow connecting *libbgcoin_wallet* and *libbgcoin_node* libraries, because these libraries are intended to be modular and not depend on each other's internal implementation details. But wallet code is still able to call node code indirectly through the `interfaces::Chain` abstract class in [`interfaces/chain.h`](../../src/interfaces/chain.h) and node code calls wallet code through the `interfaces::ChainClient` and `interfaces::Chain::Notifications` abstract classes in the same file. In general, defining abstract classes in [`src/interfaces/`](../../src/interfaces/) can be a convenient way of avoiding unwanted direct dependencies or circular dependencies between libraries.

- *libbgcoin_crypto* should be a standalone dependency that any library can depend on, and it should not depend on any other libraries itself.

- *libbgcoin_consensus* should only depend on *libbgcoin_crypto*, and all other libraries besides *libbgcoin_crypto* should be allowed to depend on it.

- *libbgcoin_util* should be a standalone dependency that any library can depend on, and it should not depend on other libraries except *libbgcoin_crypto*. It provides basic utilities that fill in gaps in the C++ standard library and provide lightweight abstractions over platform-specific features. Since the util library is distributed with the kernel and is usable by kernel applications, it shouldn't contain functions that external code shouldn't call, like higher level code targeted at the node or wallet. (*libbgcoin_common* is a better place for higher level code, or code that is meant to be used by internal applications only.)

- *libbgcoin_common* is a home for miscellaneous shared code used by different Bitcoin Core applications. It should not depend on anything other than *libbgcoin_util*, *libbgcoin_consensus*, and *libbgcoin_crypto*.

- *libbgcoin_kernel* should only depend on *libbgcoin_util*, *libbgcoin_consensus*, and *libbgcoin_crypto*.

- The only thing that should depend on *libbgcoin_kernel* internally should be *libbgcoin_node*. GUI and wallet libraries *libbgcoinqt* and *libbgcoin_wallet* in particular should not depend on *libbgcoin_kernel* and the unneeded functionality it would pull in, like block validation. To the extent that GUI and wallet code need scripting and signing functionality, they should be get able it from *libbgcoin_consensus*, *libbgcoin_common*, *libbgcoin_crypto*, and *libbgcoin_util*, instead of *libbgcoin_kernel*.

- GUI, node, and wallet code internal implementations should all be independent of each other, and the *libbgcoinqt*, *libbgcoin_node*, *libbgcoin_wallet* libraries should never reference each other's symbols. They should only call each other through [`src/interfaces/`](../../src/interfaces/) abstract interfaces.

## Work in progress

- Validation code is moving from *libbgcoin_node* to *libbgcoin_kernel* as part of [The libbgcoinkernel Project #27587](https://github.com/BGCoinDev/bgcoin/issues/27587)
