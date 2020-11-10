# **`SX Utils`**

[![Build Status](https://travis-ci.org/stableex/sx.utils.svg?branch=master)](https://travis-ci.org/stableex/sx.utils)

## Quickstart

```c++
#include <sx.utils/utils.hpp"

const asset quantity = asset{10000, symbol{"EOS", 4}};
const double amount = sx::utils::asset_to_double( quantity );
// => 1.0
```

## Table of Content

- [STATIC `double_to_asset`](#static-double_to_asset)
- [STATIC `asset_to_double`](#static-asset_to_double)
- [STATIC `sort_tokens`](#static-sort_tokens)

## STATIC `double_to_asset`

Convert double to asset

### params

- `{double} amount` - amount
- `{symbol} symbol` - symbol

### returns

- `{asset}` - token

### example

```c++
const double amount = 1.0;
const symbol sym = symbol{"EOS", 4};
const asset token = sx::utils::double_to_asset( amount, sym );
// => "1.0000 EOS"
```

## STATIC `asset_to_double`

Convert asset to double

### params

- `{asset} quantity` - quantity

### returns

- `{double}` - amount

### example

```c++
const asset quantity = asset{10000, symbol{"EOS", 4}};
const double amount = sx::utils::asset_to_double( quantity );
// => 1.0
```


## STATIC `sort_tokens`

Returns sorted token assets, used to handle return values from pairs sorted in this order

### params

- `{asset} a` - token A
- `{asset} b` - token B

### returns

- `{pair<asset, asset>}` - sorted tokens

### example

```c++
// Inputs
const asset a = asset{10000, symbol{"USDT", 4}};
const asset b = asset{10000, symbol{"EOS", 4}};

// Sort
const auto[ token0, token1 ] = sx::utils::sort_tokens( a, b );
// token0 => "1.0000 EOS"
// token1 => "1.0000 USDT"
```

## STATIC `split`

Split string into tokens

### params

- `{string} str` - string to split
- `{string} delim` - delimiter (ex: ",")

### returns

- `{vector<string>}` - tokenized strings

### example

```c++
const auto[ token0, token1 ] = sx::utils::split( "foo,bar", "," );
// token0 => "foo"
// token1 => "bar"
```