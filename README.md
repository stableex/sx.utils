# **`SX Utils`**

[![Build Status](https://travis-ci.org/stableex/sx.utils.svg?branch=main)](https://travis-ci.org/stableex/sx.utils)

## Quickstart

```c++
#include <sx.utils/utils.hpp>

const asset quantity = asset{10000, symbol{"EOS", 4}};
const double amount = sx::utils::asset_to_double( quantity );
// => 1.0
```

## Table of Content

- [STATIC `double_to_asset`](#static-double_to_asset)
- [STATIC `asset_to_double`](#static-asset_to_double)
- [STATIC `sort_tokens`](#static-sort_tokens)
- [STATIC `parse_name`](#static-parse_name)
- [STATIC `parse_symbol_code`](#static-parse_symbol_code)
- [STATIC `parse_symbol`](#static-parse_symbol)
- [STATIC `parse_asset`](#static-parse_asset)
- [STATIC `parse_extended_symbol`](#static-parse_extended_symbol)
- [STATIC `parse_extended_asset`](#static-parse_extended_asset)
- [STATIC `get_balance`](#static-get_balance)
- [STATIC `get_supply`](#static-get_supply)

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


## STATIC `parse_name`

Parse string for account name without failing

### params

- `{string} str` - string to parse

### returns

- `{name}` - converted name, `name{}` if invalid

### example

```c++
const auto contract = sx::utils::parse_name( "test.sx" );
eosio::check(contract.is_valid(), "Invalid contract name");
// => "test_sx"_n
```

## STATIC `parse_symbol_code`

Parse string for symbol code without failing

### params

- `{string} str` - string to parse

### returns

- `{symbol_code}` - converted symbol code, `symbol_code{}` if invalid

### example

```c++
const auto symcode = sx::utils::parse_symbol_code( "SXEOS" );
eosio::check(symcode.is_valid(), "Invalid symbol code");
```

## STATIC `parse_symbol`

Parse string for symbol without failing

### params

- `{string} str` - string to parse

### returns

- `{symbol}` - converted symbol, `symbol{}` if invalid

### example

```c++
const auto sym = sx::utils::parse_symbol( "4,SXEOS" );
eosio::check(sym.is_valid(), "Invalid symbol");
```

## STATIC `parse_asset`

Parse string for asset without failing

### params

- `{string} str` - string to parse

### returns

- `{asset}` - converted asset, `asset{}` if invalid

### example

```c++
const auto quantity = sx::utils::parse_asset( "20.0000 SXEOS" );
eosio::check(quantity.symbol.is_valid(), "Invalid asset");
```


## STATIC `parse_extended_symbol`

Parse string for extended_symbol without failing

### params

- `{string} str` - string to parse

### returns

- `{extended_symbol}` - converted extended symbol, `extended_symbol{}` if invalid

### example

```c++
const auto ext_sym = sx::utils::parse_extended_symbol( "4,SXEOS@token.sx" );
eosio::check(ext_sym.get_symbol().is_valid(), "Invalid extended symbol");
```


## STATIC `parse_extended_asset`

Parse string for extended_asset without failing

### params

- `{string} str` - string to parse

### returns

- `{extended_asset}` - converted extended asset, `extended_asset{}` if invalid

### example

```c++
const auto ext_quantity = sx::utils::parse_extended_asset( "20.0000 SXEOS@token.sx" );
eosio::check(ext_quantity.quantity.is_valid(), "Invalid extended asset");
```

## STATIC `parse_extended_asset`

Parse string for extended_asset without failing

### params

- `{string} str` - string to parse

### returns

- `{extended_asset}` - converted extended asset, `extended_asset{}` if invalid

### example

```c++
const auto ext_quantity = sx::utils::parse_extended_asset( "20.0000 SXEOS@token.sx" );
eosio::check(ext_quantity.quantity.is_valid(), "Invalid extended asset");
```

## STATIC `get_balance`

Get account balance without failing to avoid assert errors for accounts with unopened balance 
`eosio.token::get_balance` alternative

### params

- `{extended_symbol} ext_sym` - extended symbol to query
- `{name} owner` - account to query balance for

### returns

- `{extended_asset}` - account balance, `extended_asset{}` if no opened account 

### example

```c++
const extended_symbol ext_sym { symbol{"USDT", 4}, "tethertether"_n };
const auto balance = sx::utils::get_balance(ext_sym).quantity;
eosio::check(balance.is_valid(), "Balance not opened");
```

## STATIC `get_supply`

Get token supply without failing to avoid assert errors for non-existing tokens
`eosio.token::get_supply` alternative

### params

- `{extended_symbol} ext_sym` - extended symbol to query

### returns

- `{asset}` - token supply, `asset{}` if token doesn't exist

### example

```c++
const extended_symbol ext_sym { symbol{"USDT", 4}, "tethertether"_n };
const auto supply = sx::utils::get_supply(ext_sym);
eosio::check(balance.is_valid(), "Token doesn't exist on this contract");
```
