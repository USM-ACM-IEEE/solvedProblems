
var entityMap = {
    "&": "&amp;",
    "<": "&lt;",
    ">": "&gt;",
    '"': '&quot;',
    "'": '&#39;',
    "/": '&#x2F;'
};

function escapeHtml(string) {
    return String(string).replace(/[&<>"'\/]/g, function (s) {
        return entityMap[s];
    });
}

function twodigit(x) {
    // There must be a better way in Javascript?
    return (x < 10 ? "0" : "") + x;
}

function format_interval(seconds, always_show_hours, verbose_days) {
    always_show_hours = typeof always_show_hours !== 'undefined' ? always_show_hours : false;
    verbose_days = typeof verbose_days !== 'undefined' ? verbose_days : false;

    var neg = seconds < 0;
    if (neg) seconds = -seconds;

    seconds = Math.floor(seconds);
    h = Math.floor(seconds / 3600);
    m = Math.floor(seconds / 60) % 60;
    s = seconds % 60;

    var res = '';

    if (verbose_days) {
        var d = Math.floor(h / 24);
        h %= 24;
        if (d > 0) {
            always_show_hours = true;
            res += d + ' day' + (d != 1 ? 's' : '') + ' ';
        }
    }

    if (h > 0 || always_show_hours) {
        res += h + ':';
    }

    res += twodigit(m) + ':' + twodigit(s);

    if (neg) res = "-" + res;

    return res;
};

function initSite() {
    jQuery(function ($) {

        $('.selectify-this').select2();

        $('[data-toggle="tooltip"]').tooltip();

        /* Site search */
        $('.site-search > a').on('click', function() {
            $(this).parent().find('input').focus();
        });

        $('.site-search > input').on('focus', function() {
            $(this).parent().addClass('active');
        });

        $('body').on('click', function(e) {

            $('.site-search').each(function () {
                if (!$(this).is(e.target) && $(this).has(e.target).length === 0) {

                    $(this).removeClass('active');

                }
            });

        });
        /* End Site search */


        // Filter dropdown
        $('#filter li a').click(function (e) {
            var text = $(this).text(),
                val = $(this).parent().attr('data-value');

            $('#main_filter_text').text(text);
            $('#filter_by').val(val);

            if (val === 'all') {
                $('#filter_by_value').prop('disabled', true);
            } else {
                $('#filter_by_value').prop('disabled', false).focus();
            }
        });

    });
}

function initContestHeader(has_start, elapsed_seconds, total_seconds) {
    var loaded_at = page_loaded_at;

    jQuery(function ($) {
        var contest_progress = $('.contest-progress'),
            update_session_info = function (cls, val) {
                if (val && !contest_progress.hasClass(cls))
                    contest_progress.addClass(cls);
                else if (!val && contest_progress.hasClass(cls))
                    contest_progress.removeClass(cls);
            };

        var last_before_long = elapsed_seconds < -30;
        var last_before = elapsed_seconds < 2;

        setInterval(function () {

            var cur_second = Math.floor(elapsed_seconds + (new Date() - loaded_at) / 1000);
            var cur_before_long = cur_second < -30;
            var cur_before = cur_second < 2;

            if (has_start && ((last_before && !cur_before) || (last_before_long && !cur_before_long))) {
                location.reload();
            }

            last_before_long = cur_before_long;
            last_before = cur_before;

            var session_nearend = false,
                session_finished = false,
                session_notstarted = false,
                session_nostart = false;

            if (!has_start) {
                session_nostart = true;
                cur_second = 0;
            } else if (cur_second < 0) {
                session_notstarted = true;
            } else if (cur_second >= total_seconds) {
                session_finished = true;
            } else if (total_seconds - cur_second <= 15 * 60) {
                session_nearend = true;
            }

            update_session_info('session-nostart', session_nostart);
            update_session_info('session-notstarted', session_notstarted);
            update_session_info('session-nearend', session_nearend);
            update_session_info('session-finished', session_finished);

            if (cur_second < 0) {
                contest_progress.find('.countdown').text(format_interval(-cur_second, false, true));
            }

            cur_second = Math.max(0, cur_second);
            cur_second = Math.min(total_seconds, cur_second);

            var prog = 0;
            if (!session_nostart) {
                prog = 100 * cur_second / total_seconds;
            }

            contest_progress.find('.count_elapsed').text(format_interval(cur_second, true));
            contest_progress.find('.count_remaining').text(format_interval(total_seconds - cur_second, true));
            contest_progress.find('.progress-bar').css('width', prog.toString() + '%');

        }, 1000);
    });

    return function (new_has_start, new_elapsed_seconds, new_total_seconds, new_loaded_at) {
        has_start = new_has_start;
        elapsed_seconds = new_elapsed_seconds;
        total_seconds = new_total_seconds;
        loaded_at = new_loaded_at;
    };
}

