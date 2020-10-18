#pragma once

#include <eosio/asset.hpp>

#include <math.h>

namespace sx {
namespace utils {

    using eosio::asset;
    using eosio::symbol;

    /**
     * ## STATIC `asset_to_double`
     *
     * Convert asset to double
     *
     * ### params
     *
     * - `{asset} quantity` - quantity
     *
     * ### returns
     *
     * - `{double}` - amount
     *
     * ### example
     *
     * ```c++
     * const asset quantity = asset{10000, symbol{"EOS", 4}};
     * const double amount = sx::utils::asset_to_double( quantity );
     * // => 1.0
     * ```
     */
    static double asset_to_double( const asset quantity )
    {
        if ( quantity.amount == 0 ) return 0.0;
        return quantity.amount / pow(10, quantity.symbol.precision());
    }

    /**
     * ## STATIC `double_to_asset`
     *
     * Convert double to asset
     *
     * ### params
     *
     * - `{double} amount` - amount
     * - `{symbol} symbol` - symbol
     *
     * ### returns
     *
     * - `{asset}` - token
     *
     * ### example
     *
     * ```c++
     * const double amount = 1.0;
     * const symbol sym = symbol{"EOS", 4};
     * const asset token = sx::utils::double_to_asset( amount, sym );
     * // => "1.0000 EOS"
     * ```
     */
    static asset double_to_asset( const double amount, const symbol sym )
    {
        return asset{ static_cast<int64_t>( amount * pow(10, sym.precision())), sym };
    }
};
}