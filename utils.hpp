#pragma once

#include <eosio/asset.hpp>

#include <math.h>

namespace sx {
namespace utils {

    using eosio::asset;
    using eosio::symbol;

    using std::string;
    using std::vector;

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

    /**
     * ## STATIC `sort_tokens`
     *
     * Returns sorted token assets, used to handle return values from pairs sorted in this order
     *
     * ### params
     *
     * - `{asset} a` - token A
     * - `{asset} b` - token B
     *
     * ### returns
     *
     * - `{pair<asset, asset>}` - sorted tokens
     *
     * ### example
     *
     * ```c++
     * // Inputs
     * const asset a = asset{10000, symbol{"USDT", 4}};
     * const asset b = asset{10000, symbol{"EOS", 4}};
     *
     * // Sort
     * const auto[ token0, token1 ] = sx::utils::sort_tokens( a, b );
     * // token0 => "1.0000 EOS"
     * // token1 => "1.0000 USDT"
     * ```
     */
    static std::pair<asset, asset> sort_tokens( const asset a, const asset b )
    {
        eosio::check(a.symbol != b.symbol, "SX.Utils: IDENTICAL_ASSETS");
        return a.symbol < b.symbol ? std::pair<asset, asset>{a, b} : std::pair<asset, asset>{b, a};
    }

    /**
     * ## STATIC `split`
     *
     * Split string into tokens
     *
     * ### params
     *
     * - `{string} str` - string to split
     * - `{string} delim` - delimiter (ex: ",")
     *
     * ### returns
     *
     * - `{vector<string>}` - tokenized strings
     *
     * ### example
     *
     * ```c++
     * const auto[ token0, token1 ] = sx::utils::split( "foo,bar", "," );
     * // token0 => "foo"
     * // token1 => "bar"
     * ```
     */
    static vector<string> split( const string str, const string delim )
    {
        vector<string> tokens;
        if ( str.size() == 0 ) return tokens;

        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == string::npos) pos = str.length();
            string token = str.substr(prev, pos-prev);
            if (token.length() > 0) tokens.push_back(token);
            prev = pos + delim.length();
        }
        while (pos < str.length() && prev < str.length());
        return tokens;
    }
};
}