// Copyright (c) 2014-2016 Thomas Fussell
// Copyright (c) 2010-2015 openpyxl
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file
#include <xlnt/styles/formattable.hpp>

namespace xlnt {

formattable::formattable()
    : apply_alignment_(false),
      apply_border_(false),
      apply_fill_(false),
      apply_font_(false),
      apply_number_format_(false),
      apply_protection_(false)
{
}

formattable::formattable(const formattable &other)
    : alignment_(other.alignment_),
      border_(other.border_),
      fill_(other.fill_),
      font_(other.font_),
      number_format_(other.number_format_),
      protection_(other.protection_),
      apply_alignment_(other.apply_alignment_),
      apply_border_(other.apply_border_),
      apply_fill_(other.apply_fill_),
      apply_font_(other.apply_font_),
      apply_number_format_(other.apply_number_format_),
      apply_protection_(other.apply_protection_)
{
}

formattable &formattable::operator=(const xlnt::formattable &other)
{
    alignment_ = other.alignment_;
    border_ = other.border_;
    fill_ = other.fill_;
    font_ = other.font_;
    number_format_ = other.number_format_;
    protection_ = other.protection_;
    
    apply_alignment_ = other.apply_alignment_;
    apply_border_ = other.apply_border_;
    apply_fill_ = other.apply_fill_;
    apply_font_ = other.apply_font_;
    apply_number_format_ = other.apply_number_format_;
    apply_protection_ = other.apply_protection_;

    return *this;
}

alignment &formattable::get_alignment()
{
    return alignment_;
}

const alignment &formattable::get_alignment() const
{
    return alignment_;
}

void formattable::set_alignment(const xlnt::alignment &new_alignment)
{
    alignment_ = new_alignment;
    alignment_applied(true);
}

number_format &formattable::get_number_format()
{
    return number_format_;
}

const number_format &formattable::get_number_format() const
{
    return number_format_;
}

void formattable::set_number_format(const xlnt::number_format &new_number_format)
{
    number_format_ = new_number_format;
    number_format_applied(true);
}

border &formattable::get_border()
{
    return border_;
}

const border &formattable::get_border() const
{
    return border_;
}

void formattable::set_border(const xlnt::border &new_border)
{
    border_ = new_border;
    border_applied(true);
}

fill &formattable::get_fill()
{
    return fill_;
}

const fill &formattable::get_fill() const
{
    return fill_;
}

void formattable::set_fill(const xlnt::fill &new_fill)
{
    fill_ = new_fill;
    fill_applied(true);
}

font &formattable::get_font()
{
    return font_;
}

const font &formattable::get_font() const
{
    return font_;
}

void formattable::set_font(const xlnt::font &new_font)
{
    font_ = new_font;
    font_applied(true);
}

protection &formattable::get_protection()
{
    return protection_;
}

const protection &formattable::get_protection() const
{
    return protection_;
}

void formattable::set_protection(const xlnt::protection &new_protection)
{
    protection_ = new_protection;
    protection_applied(true);
}

std::string formattable::to_hash_string() const
{
    std::string hash_string("formattable:");
    
    hash_string.append(std::to_string(alignment_applied()));
    hash_string.append(alignment_applied() ? std::to_string(alignment_.hash()) : ":");

    hash_string.append(std::to_string(border_applied()));
    hash_string.append(border_applied() ? std::to_string(border_.hash()) : ":");

    hash_string.append(std::to_string(font_applied()));
    hash_string.append(font_applied() ? std::to_string(font_.hash()) : ":");

    hash_string.append(std::to_string(fill_applied()));
    hash_string.append(fill_applied() ? std::to_string(fill_.hash()) : ":");

    hash_string.append(std::to_string(number_format_applied()));
    hash_string.append(std::to_string(number_format_.hash()));

    hash_string.append(std::to_string(protection_applied()));
    hash_string.append(protection_applied() ? std::to_string(protection_.hash()) : ":");
    
    return hash_string;
}

void formattable::alignment_applied(bool applied)
{
    apply_alignment_ = applied;
}

void formattable::border_applied(bool applied)
{
    apply_border_ = applied;
}

void formattable::fill_applied(bool applied)
{
    apply_fill_ = applied;
}

void formattable::font_applied(bool applied)
{
    apply_font_ = applied;
}

void formattable::number_format_applied(bool applied)
{
    apply_number_format_ = applied;
}

void formattable::protection_applied(bool applied)
{
    apply_protection_ = applied;
}

bool formattable::alignment_applied() const
{
    return apply_alignment_;
}

bool formattable::border_applied() const
{
    return apply_border_;
}

bool formattable::fill_applied() const
{
    return apply_fill_;
}

bool formattable::font_applied() const
{
    return apply_font_;
}

bool formattable::number_format_applied() const
{
    return apply_number_format_;
}

bool formattable::protection_applied() const
{
    return apply_protection_;
}

} // namespace xlnt
