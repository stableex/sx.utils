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