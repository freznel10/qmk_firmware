/* Copyright 2022 Freznel B. Sta. Ana (Freznel10)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "rev4.h"

bool auto_mouse_activation(report_mouse_t mouse_report) {
    return mouse_report.x != 0|| mouse_report.y != 0 || mouse_report.h != 0|| mouse_report.v != 0 || mouse_report.buttons || (get_toggled_pointing_mode_id() == 3);
}
